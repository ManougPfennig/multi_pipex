/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:02:11 by mapfenni          #+#    #+#             */
/*   Updated: 2023/03/27 20:02:13 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dt;
	char	*sc;

	i = 0;
	dt = (char *)dst;
	sc = (char *)src;
	while (i < n && (dst || src))
	{
		dt[i] = sc[i];
		i++;
	}
	return (dst);
}
