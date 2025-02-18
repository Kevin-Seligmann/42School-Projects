/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 22:21:55 by kseligma          #+#    #+#             */
/*   Updated: 2024/09/05 22:38:10 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*right;
	t_list	*left;
	t_list	*after_right;

	if (!begin_list)
		return;
	left = NULL;
	right = *begin_list;
	while (right)
	{
		after_right = right->next;
		right->next = left;
		left = right;
		right = after_right;
	}
	*begin_list = left;
}
