/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:18:55 by kseligma          #+#    #+#             */
/*   Updated: 2023/10/29 19:18:56 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_sqrt(int nb)
{
	int	min;
	int	max;
	int	mid;
	int	sqr;

	min = 0;
	if (nb < 46342)
		max = nb / 2;
	else
		max = 46342;
	if (nb == 1)
		return (1);
	while (min <= max)
	{
		mid = (min + max) / 2;
		sqr = (mid * mid);
		if (sqr == nb)
			return (mid);
		else if (sqr > nb)
			max = mid - 1;
		else
			min = mid + 1;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	ind;

	ind = 0;
	argc = 0;
	while (ind++ < 2147483647)
	printf("Sqrt de %d es %d. IND %d\n", atoi(argv[1]), ft_sqrt(atoi(argv[1])), ind);
	return (0);
}
