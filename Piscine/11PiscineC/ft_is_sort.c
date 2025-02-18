/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:38:52 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/15 01:53:50 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	ft_is_descent_sort(int *tab, int length, int (*f)(int, int))
{
	int	ind;

	ind = 0;
	while (ind < length - 1)
	{
		if (f(tab[ind], tab[ind + 1]) < 0)
			return (0);
		ind ++;
	}
	return (1);
}

static int	ft_is_ascent_sort(int *tab, int length, int (*f)(int, int))
{
	int	ind;

	ind = 0;
	while (ind < length - 1)
	{
		if (f(tab[ind], tab[ind + 1]) > 0)
			return (0);
		ind ++;
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	ind;

	ind = 0;
	if (ft_is_ascent_sort(tab, length, f) != 0)
		return (1);
	if (ft_is_descent_sort(tab, length, f) != 0)
		return (1);
	return (0);
}
