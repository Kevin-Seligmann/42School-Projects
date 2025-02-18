/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 22:02:14 by kseligma          #+#    #+#             */
/*   Updated: 2024/09/05 22:06:23 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new_node;

	if (!begin_list)
		return ;
	new_node = ft_create_elem(data);
	if (!new_node)
		return ;
	new_node->next = (*begin_list)->next;
	*begin_list = new_node;
}
