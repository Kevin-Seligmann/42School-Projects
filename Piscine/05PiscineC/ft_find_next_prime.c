/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:40:26 by kseligma          #+#    #+#             */
/*   Updated: 2023/10/29 20:40:27 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_is_prime(int nb);
int	ft_sqrt(int nb);

int	ft_find_next_prime(int nb)
{
	while (ft_is_prime(nb) == 0)
		nb ++;
	return (nb);
}

int	ft_is_prime(int nb)
{
	int	count;
	int	boundary;

	boundary = ft_sqrt(nb);
	if (nb == 2)
		return (1);
	if (nb <= 1 || nb % 2 == 0)
		return (0);
	count = 3;
	while (count <= boundary)
	{
		if (nb % count == 0)
			return (0);
		count += 2;
	}
	return (1);
}

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
	while (min < max)
	{
		mid = (min + max) / 2;
		sqr = (mid * mid);
		if (sqr > nb)
			max = mid - 1;
		else
			min = mid + 1;
	}
	return (min);
}

/*int main(int argc, char *argv[])
{
	int ind;

	ind = 0;
	argc = 0;
	while (ind ++ < 2147395600)
		printf("Siguiente primo de
		%d es %d. IND %d\
		n", atoi(argv[1]), ft_find_ne
		xt_prime(atoi(argv[1])), ind);
	return (0);
}*/
