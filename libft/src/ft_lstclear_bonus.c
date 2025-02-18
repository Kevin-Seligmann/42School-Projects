/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:13:13 by kseligma          #+#    #+#             */
/*   Updated: 2024/01/16 20:03:43 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*node;
	t_list	*nnode;

	if (lst == 0 || del == 0)
		return ;
	node = *lst;
	while (node != 0)
	{
		nnode = node->next;
		ft_lstdelone(node, del);
		node = nnode;
	}
	*lst = 0;
}
