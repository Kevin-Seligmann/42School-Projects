/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:52:44 by kseligma          #+#    #+#             */
/*   Updated: 2023/10/26 17:52:47 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funct.h"

int	initial_char(char num);

int	ft_atoi(char *str)
{
	unsigned int	ind;
	int				sign;
	int				ans;

	ans = 0;
	sign = 1;
	ind = 0;
	while (initial_char(str[ind]) == 1)
		ind ++;
	while (str[ind] == '-' || str[ind] == '+')
	{
		if (str[ind] == '-')
			sign *= -1;
		ind ++;
	}
	while (str[ind] <= '9' && str[ind] >= '0')
	{
		ans *= 10;
		ans += str[ind] - '0';
		ind ++;
	}
	return (sign * ans);
}

int	initial_char(char num)
{
	if (num == ' ' || num == '\f' || num == '\n' || num == '\r')
		return (1);
	if (num == '\v' || num == '\t')
		return (1);
	return (0);
}

/*int	main(int argc, char *argv[])
{
	argc = 0;
	printf("%d\n", ft_atoi(argv[1]));
	return (0);
}*/
