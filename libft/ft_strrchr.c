/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:19:44 by mapfenni          #+#    #+#             */
/*   Updated: 2023/03/27 18:19:51 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, char c)
{
	int		i;
	char	*output;

	i = 0;
	output = 0;
	while (str[i])
	{
		if (str[i] == c)
			output = (str + i);
		i++;
	}
	if (c == '\0')
		return (str + i);
	return (output);
}
