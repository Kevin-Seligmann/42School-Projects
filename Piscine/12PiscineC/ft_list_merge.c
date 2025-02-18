/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 22:47:03 by kseligma          #+#    #+#             */
/*   Updated: 2024/09/05 22:48:39 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*lst1_last;

	lst1_last = ft_list_last(begin_list1);
	if (lst1_last)
		lst1_last->next = begin_list2;
	else
		*begin_list1 = begin_list2;		
}
