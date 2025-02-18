/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 22:50:41 by kseligma          #+#    #+#             */
/*   Updated: 2024/09/06 03:50:08 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static void	swap(t_list *node1, t_list *node2)
{
	void	*data;

	if (!node1 || !node2)
		return ;
	data = node1->data;
	node1->data = node2->data;
	node2->data = data;	
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*last;
	t_list	*current;
	void	*data;

	if (!begin_list)
		return ;
	last = ft_list_last(begin_list);
	while (last != begin_list)
	{
		current = begin_list;
		while (current->next != last)
		{
			swap(current, current->next);
			current = current->next;
		}
		swap(current, current->next);
		last = current;
	}
}
