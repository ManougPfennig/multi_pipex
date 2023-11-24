/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:32:47 by mapfenni          #+#    #+#             */
/*   Updated: 2023/04/04 15:59:14 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lister;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	lister = (*lst);
	while (lister->next != NULL)
		lister = lister->next;
	lister->next = new;
}
