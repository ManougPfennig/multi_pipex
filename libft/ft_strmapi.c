/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:36:43 by mapfenni          #+#    #+#             */
/*   Updated: 2023/04/06 17:21:35 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dest;
	unsigned int	len;

	if (!s || !f)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	dest = malloc((len + 1) * sizeof(char));
	if (!(dest))
		return (NULL);
	dest[len] = '\0';
	i = 0;
	while (s[i])
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	return (dest);
}
