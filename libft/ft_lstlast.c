/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:21:07 by mapfenni          #+#    #+#             */
/*   Updated: 2023/04/02 18:31:24 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	lister;

	if (!lst)
		return (NULL);
	lister.next = lst;
	while (lister.next->next != NULL)
		lister.next = lister.next->next;
	return (lister.next);
}
