/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 21:23:31 by kseligma          #+#    #+#             */
/*   Updated: 2024/01/16 22:26:52 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len ++;
	while (n != 0)
	{
		n /= 10;
		len ++;
	}
	return (len);
}

static char	*min(void)
{
	char	*m;

	m = ft_strdup("-2147483648");
	if (m == 0)
		return (0);
	return (m);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		ind;

	if (n == -2147483648)
		return (min());
	ind = 0;
	len = num_len(n);
	str = (char *) malloc(len + 1);
	if (str == 0)
		return (0);
	if (n < 0)
	{
		n *= -1;
		str[ind++] = '-';
	}
	str[len] = 0;
	while (ind < len)
	{
		str[len - 1] = n % 10 + '0';
		n /= 10;
		len --;
	}
	return (str);
}
