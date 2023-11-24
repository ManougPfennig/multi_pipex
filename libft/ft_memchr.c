/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:35:58 by mapfenni          #+#    #+#             */
/*   Updated: 2023/04/11 19:33:53 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	if (n == 0)
		return (NULL);
	str = (unsigned char *)s;
	i = 0;
	while (n--)
	{
		if (str[i] == (unsigned char)c)
			return (str + i);
		i++;
	}
	return (NULL);
}

// #include <string.h>
// #include <stdio.h>
// int main()
// {
// 	char s[] = {0, 1, 2 ,3 ,4 ,5};
// 	printf("%s", ft_memchr(s, 2, 3));
// }
