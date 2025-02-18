/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 22:06:37 by kseligma          #+#    #+#             */
/*   Updated: 2024/09/05 22:09:26 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*node;
	t_list	*last;
	if (!begin_list)
		return ;
	node = ft_create_elem(data);
	if (!node)
		return ;
	last = ft_list_last(begin_list);
	if (last)
		last->next = node;
	else
		*begin_list = node;
}
