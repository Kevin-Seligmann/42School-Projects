/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:58:21 by kseligma          #+#    #+#             */
/*   Updated: 2023/11/01 18:58:28 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	valid_base(char *base);
int	pos_in_base(char num, char *base);
int	size_calc(char *str);

int	ft_atoi_base(char *str, char *base)
{
	unsigned int	ind;
	long			ans;
	int				size;
	int				sign;

	sign = 1;
	ans = 0;
	ind = 0;
	size = size_calc(base);
	if (size == 0 || size == 1 || valid_base(base) == 0)
		return (0);
	while (pos_in_base(str[ind], "\f\n\r\v\t ") > -1)
		ind ++;
	while (pos_in_base(str[ind], "-+") > -1)
	{
		if (str[ind] == '-')
			sign *= -1;
		ind ++;
	}
	while (pos_in_base(str[ind], base) > -1)
	{
		ans = ans * size + pos_in_base(str[ind], base);
		ind ++;
	}
	return (sign * ans);
}

int	size_calc(char *str)
{
	unsigned int	size;

	size = 0;
	while (str[size] != 0)
		size ++;
	return (size);
}

int	pos_in_base(char num, char *base)
{
	int	ind;

	ind = 0;
	while (base[ind] != 0)
	{
		if (base[ind] == num)
			return (ind);
		ind ++;
	}
	return (-1);
}

int	valid_base(char *base)
{
	int	ind1;
	int	ind2;

	ind1 = 0;
	ind2 = 1;
	while (base[ind1] != 0)
	{
		ind2 = 1;
		if (pos_in_base(base[ind1], "+- \f\t\n\v\r") > -1)
			return (0);
		while (base[ind1 + ind2] != 0)
		{
			if (base[ind1 + ind2] == base[ind1])
				return (0);
			ind2 ++;
		}
		ind1 ++;
	}
	return (1);
}
