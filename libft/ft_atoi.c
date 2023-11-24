/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:24:42 by mapfenni          #+#    #+#             */
/*   Updated: 2023/03/31 22:03:44 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_wspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	mult;

	i = 0;
	result = 0;
	mult = 1;
	while (is_wspace(str[i]))
		i++;
	if ((char)str[i] == '-' || (char)str[i] == '+')
	{
		if ((char)str[i] == '-')
			mult = -1;
		i++;
	}
	while ((char)str[i] && ((char)str[i] >= '0' && (char)str[i] <= '9'))
	{
		result *= 10;
		result += ((char)str[i] - '0');
		i++;
	}
	return (result * mult);
}
