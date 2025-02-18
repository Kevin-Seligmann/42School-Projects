/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 20:37:56 by kseligma          #+#    #+#             */
/*   Updated: 2024/01/17 18:14:46 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*dcont(t_list *fnode, void *cont, void (*del)(void *))
{
	ft_lstclear(&fnode, del);
	del(cont);
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*fnode;
	t_list	*lnode;
	void	*cont;

	if (f == 0 || del == 0 || lst == 0)
		return (0);
	cont = f(lst->content);
	fnode = ft_lstnew(cont);
	if (fnode == 0)
		return (dcont(fnode, cont, del));
	while (lst->next != 0)
	{
		lst = lst->next;
		cont = f(lst->content);
		lnode = ft_lstnew(cont);
		if (lnode == 0)
			return (dcont(fnode, cont, del));
		ft_lstadd_back(&fnode, lnode);
	}
	return (fnode);
}
