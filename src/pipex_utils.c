/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:45:58 by mapfenni          #+#    #+#             */
/*   Updated: 2023/09/11 23:10:22 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	do_dup2(int fd, int replaced)
{
	if (dup2(fd, replaced) == -1)
		exit_msg("dup2 failed", NULL, NULL);
}

void	make_pipe(int pipefd[2])
{
	if (pipe(pipefd) == -1)
		exit_msg("Pipe creation failed", NULL, NULL);
}

pid_t	do_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit_msg("Fork creation failed", NULL, NULL);
	return (pid);
}

int	do_open(char *str, int oflag)
{
	int	fd;

	fd = open(str, oflag);
	if (fd == -1)
		exit_msg("Failed to open file", str, NULL);
	return (fd);
}

void	check_execve(char **arg, t_fd *fd)
{
	int	error;

	ft_free_tab(arg, fd->test);
	waitpid(0, &error, 0);
	if (error != 0)
	{
		ft_free_tab(fd->path, NULL);
		do_dup2(fd->saved[0], STDIN_FILENO);
		do_dup2(fd->saved[1], STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
}
