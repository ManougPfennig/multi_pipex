/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multipipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:11:44 by mapfenni          #+#    #+#             */
/*   Updated: 2023/11/29 15:25:14 by mapfenni         ###   ########.fr       */
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

void	change_pipe(t_fd *fd, int pip[2], int i, int ac)
{
	int	backup[2];

	pipe(backup);
	if (i == 1)
	{
		fd->in_fd = fd->infile;
		if (fd->no_input)
		{
			fd->in_fd = dup(backup[0]);
			close(backup[1]);
			close(backup[0]);
		}
		fd->out_fd = pip[1];
		if (ac == 3)
			fd->out_fd = fd->outfile;
	}
	else
	{
		fd->in_fd = fd->copy;
		fd->out_fd = pip[1];
		if (i == ac - 2)
			fd->out_fd = fd->outfile;
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

void	multipipex(char **av, int ac)
{
	char	**arg;
	int		i;
	t_fd	*fd;
	t_fd	data;

	fd = &data;
	i = 0;
	main_start(ac, fd, av);
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
	ft_free_tab(fd->path, NULL);
}
