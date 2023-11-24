/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:18:31 by mapfenni          #+#    #+#             */
/*   Updated: 2023/04/06 17:40:24 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		length;
	char	*dest;

	i = 0;
	j = 0;
	length = 0;
	while (s1[i++])
		length++;
	while (s2[j++])
		length++;
	i = 0;
	j = 0;
	dest = malloc((length + 1) * sizeof(char));
	if (!(dest))
		return (NULL);
	dest[length] = '\0';
	while (s1[i])
		dest[j++] = s1[i++];
	i = 0;
	while (s2[i])
		dest[j++] = s2[i++];
	return (dest);
}

/*#include <stdio.h>
int	main(int ac, char **av)
{
	printf("%s + %s =\n", av[1], av[2]);
	printf("%s\n", ft_strjoin(av[1], av[2]));
	(void) ac;
}*/