/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 02:55:50 by kseligma          #+#    #+#             */
/*   Updated: 2024/09/06 03:31:38 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)())
{
	t_list	*prev;
	t_list	*current_l1;
	t_list	*next_l2;

	if (!begin_list1)
		return;
	prev = NULL;
	current_l1 = *begin_list1;
	while (begin_list2)
	{
		next_l2 = begin_list2->next;
		while (current_l1 && cmp(current_l1->data, begin_list2->data) < 0)
		{
			prev = current_l1;
			current_l1 = current_l1->next;
		}
		if (prev)
			prev->next = begin_list2;
		else
			*begin_list1 = begin_list2;
		begin_list2->next = current_l1;
		prev = begin_list2;
		begin_list2 = next_l2;
	}
}
