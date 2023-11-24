/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:12:22 by mapfenni          #+#    #+#             */
/*   Updated: 2023/04/06 17:19:46 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*plist1;
	t_list	*plist2;

	if (!lst || !(*lst) || !del)
		return ;
	plist1 = (*lst);
	plist2 = (*lst);
	(*lst) = NULL;
	while (plist1->next != NULL)
	{
		plist2 = plist1->next;
		del(plist1->content);
		free(plist1);
		plist1 = plist2;
	}
	del(plist1->content);
	free(plist1);
}
