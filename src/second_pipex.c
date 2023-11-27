/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_pipex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 23:44:36 by mapfenni          #+#    #+#             */
/*   Updated: 2023/11/26 15:55:49 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	command_test(char **arg, t_fd *fd)
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

void	second_pipex(t_fd *fd, char **av)
{
	char	**command;
	pid_t	pid;
	int		pip[2];

	fd->path = ft_split("/usr/local/sbin/:/usr/local/bin/:/usr/sbin/:/usr/bin/:\
	/sbin/:/bin/:/usr/games/:/usr/local/games/:/snap/bin/:/snap/bin/", ':');
	fd->outfile = open(ft_lastav(av), O_WRONLY | O_TRUNC);
	if (check_commands(av[3], fd) == 0)
		exit_msg("Unvalid command used", NULL, fd->path);
	command = ft_split(av[3], ' ');
	pipe(pip);
	do_dup2(pip[0], STDIN_FILENO);
	do_dup2(fd->outfile, STDOUT_FILENO);
	pid = fork();
	if (pid == 0)
		command_test(command, fd);
	ft_free_tab(command, NULL);
	ft_free_tab(fd->path, NULL);
	exit(EXIT_SUCCESS);
}
