/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 22:44:47 by kseligma          #+#    #+#             */
/*   Updated: 2024/09/06 01:02:54 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*node;
	t_list	*next;
	t_list	*prev;

	if (!begin_list)
		return ;
	node = *begin_list;
	prev = NULL;
	while (node)
	{
		next = node->next;
		if (cmp && cmp(node->data, data_ref) == 0)
		{
			if (free_fct)
				free_fct(node->data);
			free(node);
			if (node == *begin_list)
				*begin_list = next;
			else
				prev->next = next;
		}
		else
			prev = node;
		node = next;
	}
}
