/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:28:23 by mapfenni          #+#    #+#             */
/*   Updated: 2023/09/21 15:35:37 by mapfenni         ###   ########.fr       */
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

void	check_files(t_fd *fd, char **av)
{
	int	temp;

	if (access(av[1], F_OK) != 0)
	{
		ft_printf("Input file does not exist -> %s\n", av[1]);
		second_pipex(fd, av);
	}
	temp = open(av[1], O_RDONLY);
	if (temp == -1)
	{
		close(temp);
		ft_printf("Cannot open input file -> %s\n", av[1]);
		second_pipex(fd, av);
	}
	close(temp);
	temp = open(ft_lastav(av), O_WRONLY | O_TRUNC);
	if (temp == -1)
		exit_msg("Cannot write to output file -> ", ft_lastav(av), NULL);
	close(temp);
}

int	check_commands(char *av, t_fd *fd)
{
	int		i;
	int		check;
	char	*path;
	char	**arg;

	i = 0;
	check = 0;
	path = NULL;
	arg = ft_split(av, ' ');
	if (access(arg[0], F_OK) == 0)
		check++;
	while (fd->path[i])
	{
		path = ft_strjoin(fd->path[i], arg[0]);
		if (access(path, F_OK) == 0)
			check++;
		i++;
		ft_free_tab(NULL, path);
		path = NULL;
	}
	ft_free_tab(arg, path);
	if (check)
		return (1);
	return (0);
}

void	parsing(int ac, char **av, t_fd *fd)
{
	int	i;

	i = 0;
	if (ac != 5)
		exit_msg("Unvalid amount of arguments", NULL, NULL);
	check_files(fd, av);
	while (av[i])
	{
		if (ft_strlen(av[i]) == 0)
			exit_msg("Unvalid argument", NULL, NULL);
		i++;
	}
	fd->path = ft_split("/usr/local/sbin/:/usr/local/bin/:/usr/sbin/:/usr/bin/:\
	/sbin/:/bin/:/usr/games/:/usr/local/games/:/snap/bin/:/snap/bin/", ':');
	if (check_commands(av[2], fd) == 0)
	{
		ft_printf("Error : Unvalid command used");
		ft_free_tab(fd->path, NULL);
		second_pipex(fd, av);
	}
	if (check_commands(av[3], fd) == 0)
		exit_msg("Unvalid command used", NULL, fd->path);
}
