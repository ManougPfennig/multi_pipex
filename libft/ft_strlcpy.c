/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:10:58 by mapfenni          #+#    #+#             */
/*   Updated: 2023/04/09 20:19:23 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	int		dest_size;
	size_t	i;

	if (size == 0)
		return (ft_strlen((char *)src));
	dest_size = 0;
	while ((char)dest[dest_size] != '\0')
		dest_size++;
	i = 0;
	while ((char)src[i] != '\0' && (int)i < (int)size - 1)
	{
		dest[i] = (char)src[i];
		i++;
	}
	if ((int)i < (int)size)
		dest[i] = '\0';
	return (ft_strlen((char *)src));
}
