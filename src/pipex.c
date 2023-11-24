/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:07:06 by mapfenni          #+#    #+#             */
/*   Updated: 2023/09/21 11:57:00 by mapfenni         ###   ########.fr       */
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

int	first_command(char **arg, t_fd *fd)
{
	pid_t	pid;
	int		cp;

	pid = do_fork();
	if (pid == 0)
	{
		close(fd->pipe[0]);
		do_dup2(fd->infile, STDIN_FILENO);
		do_dup2(fd->pipe[1], STDOUT_FILENO);
		loop_test(arg, fd);
	}
	cp = dup(fd->pipe[0]);
	close(fd->pipe[0]);
	close(fd->pipe[1]);
	return (cp);
}

void	last_command(char **arg, t_fd *fd, int fd_cp)
{
	pid_t	pid;

	pid = do_fork();
	if (pid == 0)
	{
		do_dup2(fd_cp, STDIN_FILENO);
		do_dup2(fd->outfile, STDOUT_FILENO);
		loop_test(arg, fd);
	}
	close(fd_cp);
}

void	pipex(char **av, t_fd *fd)
{
	char	**arg;
	int		fd_cp;

	arg = ft_split(av[2], ' ');
	fd_cp = first_command(arg, fd);
	check_execve(arg, fd);
	arg = ft_split(av[3], ' ');
	last_command(arg, fd, fd_cp);
	check_execve(arg, fd);
}
