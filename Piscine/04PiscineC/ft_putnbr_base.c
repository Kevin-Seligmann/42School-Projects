/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:01:16 by kseligma          #+#    #+#             */
/*   Updated: 2023/10/26 20:01:19 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		valid_base(char *base);
int		size_calc(long nb, int b_size);
long	power_of_n(int exp, int n);

void	ft_putnbr_base(int nbr, char *base)
{
	int		size;
	int		b_size;
	long	snbr;
	char	character;

	snbr = nbr;
	b_size = valid_base(base);
	if (b_size == 0)
		return ;
	if (snbr == 0)
		write(1, &base[0], 1);
	if (snbr < 0)
	{
		write(1, "-", 1);
		snbr *= -1;
	}
	size = size_calc(snbr, b_size);
	while (size > 0)
	{
		character = base[(snbr / (power_of_n(size - 1, b_size)) % b_size)];
		write(1, &character, 1);
		size --;
	}
}

int	size_calc(long nb, int b_size)
{
	int	size;

	size = 0;
	while (nb > 0)
	{
		size ++;
		nb /= b_size;
	}
	return (size);
}

long	power_of_n(int exp, int n)
{
	long	pow;
	int		lt_exp;

	pow = 1;
	lt_exp = 0;
	while (lt_exp < exp)
	{
		pow *= n;
		lt_exp ++;
	}
	return (pow);
}

int	valid_base(char *base)
{
	int	ind1;
	int	ind2;

	ind1 = 0;
	if (base[0] == 0)
		return (0);
	if (base[1] == 0)
		return (0);
	while (base[ind1] != 0)
	{
		ind2 = 1;
		if (base[ind1] == '-' || base[ind1] == '+' || base[ind1] == '\v'
			|| base[ind1] == '\f' || base[ind1] == '\n' || base[ind1] == '\r'
			|| base[ind1] == '\t' || base[ind1] == ' ')
			return (0);
		while (base[ind1 + ind2] != 0)
		{
			if (base[ind1 + ind2] == base[ind1])
				return (0);
			ind2 ++;
		}
		ind1 ++;
	}
	return (ind1);
}

/*int	main(void)
{
	ft_putnbr(10);
	return (0);
}*/
