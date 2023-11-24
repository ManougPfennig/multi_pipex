/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:50:23 by mapfenni          #+#    #+#             */
/*   Updated: 2023/04/02 18:19:03 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	lister;

	if (!lst)
		return (0);
	lister.next = lst;
	size = 1;
	while (lister.next->next != NULL)
	{
		lister.next = lister.next->next;
		size++;
	}
	return (size);
}
