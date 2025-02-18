/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 22:19:49 by kseligma          #+#    #+#             */
/*   Updated: 2024/09/05 22:21:44 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	int	ind;

	ind = 0;
	while (begin_list)
	{
		if (ind == nbr)
			return (begin_list);
		ind ++;
		begin_list = begin_list->next;
	}
	return (NULL);
}
