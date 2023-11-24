/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:54:08 by mapfenni          #+#    #+#             */
/*   Updated: 2023/04/05 19:10:57 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	if (count && SIZE_MAX / count < size)
		return (NULL);
	str = malloc(count * size);
	if (!(str))
		return (NULL);
	ft_bzero(str, count * size);
	return (str);
}
