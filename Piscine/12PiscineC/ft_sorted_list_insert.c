/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list_insert.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 22:53:47 by kseligma          #+#    #+#             */
/*   Updated: 2024/09/06 02:54:04 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*current;
	t_list	*new;
	t_list	*prev;

	if (!begin_list || !cmp)
		return ;
	new = ft_create_elem(data);
	if (!new)
		return ;
	current = *begin_list;
	prev = NULL;
	while (current && cmp(current->data, data) < 0)
	{
		prev = current;
		current = current->next;
	}
	new->next = current;
	if (prev)
		prev->next = new;
	else
		*begin_list = new;
}
