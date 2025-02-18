/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:41:01 by kseligma          #+#    #+#             */
/*   Updated: 2023/10/31 18:41:02 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	ind;
	int	min_o;

	min_o = min;
	ind = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = (int *)malloc((max - min) * 4);
	if (*range == NULL)
		return (-1);
	while (min < max)
	{
		range[0][ind] = min;
		min ++;
		ind ++;
	}
	return ((max - min_o));
}
