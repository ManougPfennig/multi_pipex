/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:28:23 by mapfenni          #+#    #+#             */
/*   Updated: 2023/11/29 15:27:53 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_lastav(char **av)
{
	int	i;

	i = 0;
	while (av[i] != NULL)
		i++;
	return (av[i - 1]);
}

void	check_files(char **av, t_fd *fd)
{
	int	temp;

	temp = open(av[0], O_RDONLY);
	if (access(av[0], F_OK) != 0)
	{
		ft_printf("Input file does not exist: %s\n", av[0]);
		fd->no_input = 1;
	}
	else if (temp == -1)
	{
		ft_printf("Permission denied: %s\n", av[0]);
		fd->no_input = 1;
	}
	close(temp);
	temp = open(ft_lastav(av), O_WRONLY | O_TRUNC);
	if (temp == -1)
		exit_msg("Permission denied: ", ft_lastav(av), NULL);
	close(temp);
}

void	parsing(char **av, t_fd *fd)
{
	fd->no_input = 0;
	check_files(av, fd);
	fd->path = ft_split("/usr/local/sbin/:/usr/local/bin/:/usr/sbin/:/usr/bin/:\
	/sbin/:/bin/:/usr/games/:/usr/local/games/:/snap/bin/:/snap/bin/", ':');
}

void	main_start(int ac, t_fd *fd, char **av)
{
	int	temp;

	temp = -1;
	if (ac < 3)
		exit_msg("Unvalid amount of arguments", NULL, NULL);
	if (access(ft_lastav(av), F_OK) != 0 && ft_strlen(ft_lastav(av)) > 0)
		temp = open(ft_lastav(av), O_CREAT, 0666);
	else if (access(ft_lastav(av), F_OK) != 0)
		exit_msg("Invalid output name", NULL, NULL);
	if (temp != -1)
		close(temp);
	fd->saved[0] = dup(STDIN_FILENO);
	fd->saved[1] = dup(STDOUT_FILENO);
	parsing(av, fd);
	fd->infile = open(av[0], O_RDONLY);
	fd->outfile = do_open(ft_lastav(av), O_WRONLY);
	fd->test = NULL;
}
