/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:39:14 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/15 01:47:16 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*res;
	int	ind;

	ind = 0;
	res = malloc(length * sizeof(int));
	if (res == 0)
		return (0);
	while (ind < length)
	{
		res[ind] = f(tab[ind]);
		ind ++;
	}
	return (res);
}
