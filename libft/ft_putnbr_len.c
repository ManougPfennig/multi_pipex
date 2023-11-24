/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 01:07:24 by mapfenni          #+#    #+#             */
/*   Updated: 2023/04/09 18:05:09 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_len(int nb)
{
	int	total;

	total = 1;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		ft_putchar('-');
		total++;
		nb = nb * -1;
	}
	if (nb >= 10)
		total += ft_putnbr_len(nb / 10);
	ft_putchar((nb % 10) + 48);
	return (total);
}

int	ft_putnbr_u_len(unsigned int nb)
{
	int	total;

	total = 1;
	if (nb >= 10)
		total += ft_putnbr_len(nb / 10);
	ft_putchar((nb % 10) + 48);
	return (total);
}
