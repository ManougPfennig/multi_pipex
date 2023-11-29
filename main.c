/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:53:50 by mapfenni          #+#    #+#             */
/*   Updated: 2023/11/29 14:52:34 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av)
{
	t_fd	*fd;
	t_fd	data;
	int		temp;

	fd = &data;
	temp = -1;
	av++;
	ac--;
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
	multipipex(av, fd, ac);
	ft_free_tab(fd->path, NULL);
}
