/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 00:54:53 by kseligma          #+#    #+#             */
/*   Updated: 2024/09/06 01:00:11 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*iteration_head;
	t_list	*iteration_node;
	void	*data;

	if (!begin_list)
		return
	iteration_head = *begin_list;
	while (iteration_head)
	{
		iteration_node = iteration_head;
		while (iteration_node->next)
		{
			if (cmp(iteration_node->data, iteration_node->next->data) > 0)
			{
				data = iteration_node->data;
				iteration_node->data = iteration_node->next->data;
				iteration_node->next->data = data;
			}
			iteration_node = iteration_node->next;
		}
		iteration_head = iteration_head->next;
	}	
}
