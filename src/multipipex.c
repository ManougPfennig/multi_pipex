/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multipipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:11:44 by mapfenni          #+#    #+#             */
/*   Updated: 2023/11/27 18:48:45 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	loop_test(char **arg, t_fd *fd)
{
	int	i;

	i = 0;
	while (fd->path[i])
	{
		fd->test = ft_strjoin(fd->path[i], arg[0]);
		execve(arg[0], arg, NULL);
		if (execve(fd->test, arg, NULL) == -1)
			i++;
		ft_free_tab(NULL, fd->test);
	}
	exit(EXIT_FAILURE);
}

void	check_execution(char **arg, t_fd *fd)
{
	int	error;

	error = 0;
	waitpid(0, &error, 0);
	if (error)
		printf("Unvalid command used: %s\n", arg[0]);
	ft_free_tab(arg, fd->test);
}

void	print_error(char *str, t_fd *fd)
{
	do_dup2(fd->saved[1], STDOUT_FILENO);
	printf("%s", str);
	do_dup2(fd->out_fd, STDOUT_FILENO);
}

void	change_pipe(t_fd *fd, int pip[2], int i, int ac)
{
	if (i == 2)
	{
		fd->in_fd = fd->infile;
		fd->out_fd = pip[1];
	}
	else if (i == ac - 2)
	{
		fd->in_fd = fd->copy;
		fd->out_fd = fd->outfile;
	}
	else
	{
		fd->in_fd = fd->copy;
		fd->out_fd = pip[1];
	}
}

void	exec_command(char **arg, t_fd *fd, int i, int ac)
{
	pid_t	pid;
	int		pip[2];

	pipe(pip);
	change_pipe(fd, pip, i, ac);
	pid = do_fork();
	if (pid == 0)
	{
		close(pip[0]);
		do_dup2(fd->in_fd, STDIN_FILENO);
		do_dup2(fd->out_fd, STDOUT_FILENO);
		loop_test(arg, fd);
	}
	fd->copy = dup(pip[0]);
	close(pip[0]);
	close(pip[1]);
}

void	multipipex(char **av, t_fd *fd, int ac)
{
	char	**arg;
	int		i;

	i = 1;
	while (++i != ac - 1)
	{
		arg = ft_split(av[i], ' ');
		if (ft_strlen(arg[0]) == 0)
			print_error("Unvalid command used\n", fd);
		else
		{
			exec_command(arg, fd, i, ac);
			check_execution(arg, fd);
		}
	}
}
