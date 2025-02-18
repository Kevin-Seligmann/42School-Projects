/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:07:34 by kseligma          #+#    #+#             */
/*   Updated: 2023/10/26 15:07:36 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	power_of_ten(int exp);
int	size_calc(int nb);
int	excepciones(int nb);

void	ft_putnbr(int nb)
{
	int		size;
	char	character;

	nb = excepciones(nb);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	size = size_calc(nb);
	while (size > 0)
	{
		character = (nb / (power_of_ten(size - 1))) % 10 + 48;
		write(1, &character, 1);
		size --;
	}
}

int	excepciones(int nb)
{
	if (nb == 0)
		write(1, "0", 1);
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (0);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		return (-nb);
	}
	return (nb);
}

int	size_calc(int nb)
{
	int	size;

	size = 0;
	while (nb > 0)
	{
		size ++;
		nb /= 10;
	}
	return (size);
}

int	power_of_ten(int exp)
{
	int	pow;
	int	lt_exp;

	pow = 1;
	lt_exp = 0;
	while (lt_exp < exp)
	{
		pow *= 10;
		lt_exp ++;
	}
	return (pow);
}

/*int	main(void)
{
	ft_putnbr(10);
	return (0);
}*/
