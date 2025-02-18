/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:58:06 by kseligma          #+#    #+#             */
/*   Updated: 2023/11/01 18:58:09 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_atoi_base(char *str, char *base);
char	*reverse(char *str);
int		pos_in_base(char num, char *base);
int		size_calc(char *str);
int		valid_base(char *base);
int		valid_inputs(char *base_from, char *base_to, long *nbr_10, char **ans);
int		valid_nbr(char *nbr, char *base_from);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	nbr_10;
	int		size;
	int		ind;
	char	*ans;

	ind = 0;
	nbr_10 = ft_atoi_base(nbr, base_from);
	ans = (char *)malloc(34);
	if (nbr_10 <= 0)
		ind ++;
	size = valid_inputs(base_from, base_to, &nbr_10, &ans);
	if (ans == 0 || size == 0)
		return (0);
	while (nbr_10 != 0)
	{
		ans[ind] = base_to[nbr_10 % size];
		nbr_10 /= size;
		ind ++;
	}
	ans[ind] = 0;
	return (reverse(ans));
}

int	valid_inputs(char *base_from, char *base_to, long *nbr_10, char **ans)
{
	int	size_to;
	int	size_from;

	size_to = size_calc(base_to);
	size_from = size_calc(base_from);
	if (valid_base(base_to) == 0)
		return (0);
	if (valid_base(base_from) == 0)
		return (0);
	if (size_from < 2)
		return (0);
	if (size_to < 2)
		return (0);
	if (*nbr_10 < 0)
	{
		*nbr_10 *= -1;
		ans[0][0] = '-';
	}
	if (*nbr_10 == 0)
		ans[0][0] = base_to[0];
	return (size_to);
}

char	*reverse(char *str)
{
	int		moves;
	int		ind;
	int		size;
	int		neg;
	char	aux;

	neg = 0;
	if (str[0] == '-')
	{
		str ++;
		neg = 1;
	}
	size = size_calc(str);
	ind = 0;
	moves = size / 2;
	while (ind < moves)
	{
		aux = str[ind];
		str[ind] = str[size - ind - 1];
		str[size - ind - 1] = aux;
		ind ++;
	}
	if (neg)
		str --;
	return (str);
}

int	main(int argc, char	*argv[])
{
	argc = 0;
	printf("%s\n", ft_convert_base(argv[1], argv[2], argv[3]));
	return (0);
}
