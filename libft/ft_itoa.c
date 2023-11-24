/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:42:27 by mapfenni          #+#    #+#             */
/*   Updated: 2023/03/30 16:48:08 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len(long nb)
{
	int		len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nb)
{
	char	*array;
	long	n;
	int		i;

	n = nb;
	i = len(n);
	array = malloc(sizeof(char) * (i + 1));
	if (!(array))
		return (NULL);
	array[i--] = '\0';
	if (n == 0)
		array[0] = '0';
	if (n < 0)
	{
		array[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		array[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (array);
}
