/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:45:42 by mapfenni          #+#    #+#             */
/*   Updated: 2023/04/06 17:35:19 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == '\0' || needle == NULL)
		return ((char *)hay);
	if (!hay && len == 0)
		return (NULL);
	while (hay[i] != '\0' && i < len)
	{
		j = 0;
		while (needle[j] == hay[i + j] && (i + j < len))
		{
			if (needle[j + 1] == '\0')
				return ((char *)hay + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

// #include <string.h>
// #include <stdio.h>
// int main()
// {
// 	char *hay = "";
// 	char *needle = "nan";

// 	printf("%s\n", ft_strnstr((void *)0, "fake", 3));
// 	// printf("%s\n", strnstr((void *)0, "fake", 3));
// }