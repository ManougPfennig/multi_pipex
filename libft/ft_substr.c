/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:34:58 by mapfenni          #+#    #+#             */
/*   Updated: 2023/04/04 20:18:54 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		j;
	char		*new;

	if (!s)
		return (NULL);
	new = malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
		{
			new[j] = s[i];
			j++;
		}
		i++;
	}
	new[j] = '\0';
	return (new);
}

// #include <stdio.h>
// int	main()
// {
// 	printf("--> %s\n", ft_substr("ouga bouga", 400, 20));
// }