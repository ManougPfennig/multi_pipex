/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:08:48 by mapfenni          #+#    #+#             */
/*   Updated: 2023/04/06 17:22:13 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sep(char c, char charset)
{
	if (charset == c)
		return (1);
	if (c == '\0')
		return (1);
	return (0);
}

int	ft_word_number(char *str, char charset)
{
	int	i;
	int	number;

	i = 0;
	number = 0;
	while (str[i])
	{
		if (ft_sep(str[i + 1], charset) == 1
			&& ft_sep(str[i], charset) == 0)
			number++;
		i++;
	}
	return (number);
}

char	*ft_copy_word(char *dest, char *str, char charset)
{
	int	i;

	i = 0;
	while (ft_sep(str[i], charset) == 0)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_fill_tab(char **split, char *str, char charset)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (ft_sep(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (ft_sep(str[i + j], charset) == 0)
				j++;
			split[count] = (char *)malloc(sizeof(char) * (j + 1));
			ft_copy_word(split[count], str + i, charset);
			i = i + j;
			count++;
		}
	}
}

char	**ft_split(const char *str, char charset)
{
	int		tab_len;
	char	**tab;

	if (!str)
		return (NULL);
	tab_len = ft_word_number((char *)str, charset);
	tab = (char **)malloc(sizeof(char *) * (tab_len + 1));
	if (!tab)
		return (NULL);
	tab[tab_len] = 0;
	ft_fill_tab(tab, (char *)str, charset);
	return (tab);
}

/*#include <stdio.h>
int	main(int ac, char **av)
{
	int		i;
	char	**print = ft_split(av[1], av[2][0]);

	i = 0;
	while (print[i])
	{
		printf("%s\n", print[i]);
		i++;
	}
	(void)ac;
}*/