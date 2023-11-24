/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:28:47 by mapfenni          #+#    #+#             */
/*   Updated: 2023/04/04 16:35:57 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*plist;

	if (!lst)
		return ;
	plist = lst;
	while (plist->next != NULL)
	{
		f(plist->content);
		plist = plist->next;
	}
	f(plist->content);
}
