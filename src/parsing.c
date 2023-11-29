/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:28:23 by mapfenni          #+#    #+#             */
/*   Updated: 2023/11/29 14:52:17 by mapfenni         ###   ########.fr       */
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
