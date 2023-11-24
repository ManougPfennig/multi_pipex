/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:50:08 by mapfenni          #+#    #+#             */
/*   Updated: 2023/04/17 19:03:33 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dst_len;
	unsigned int	src_len;

	src_len = (unsigned int)ft_strlen(src);
	if (size == 0)
		return (src_len);
	dst_len = (unsigned int)ft_strlen(dest);
	if (dst_len >= size)
		return (src_len + size);
	dest += dst_len;
	size -= dst_len;
	while (*src && --size)
		*dest++ = *src++;
	*dest = '\0';
	return (dst_len + src_len);
}

// #include <string.h>
// #include <stdio.h>
// int main()
// {
// 	printf("%u", ft_strlcat("toto", "", 10));
// }
