/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:59:52 by kseligma          #+#    #+#             */
/*   Updated: 2023/10/19 18:14:13 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	size_calculator(int nb);
int		power_of_ten(char pow);
void	exceptions(int nb);

void	ft_putnbr(int nb)
{
	char	number_string[10];
	char	size;
	int		current_dig;
	int		ind;

	exceptions(nb);
	if (nb < 0)
	{
		nb *= -1;
	}
	size = size_calculator(nb);
	current_dig = power_of_ten(size - 1);
	ind = 0;
	while (ind < size)
	{
		number_string[ind] = nb / current_dig % 10 + 48;
		ind ++;
		current_dig = current_dig / 10;
	}
	write(1, &number_string, size);
}

void	exceptions(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
	}
	else if (nb == 0)
	{
		write(1, "0", 1);
	}
}

char	size_calculator(int nb)
{
	char	digit;

	digit = 1;
	while (nb > 0)
	{
		nb = nb / 10;
		digit ++;
	}
	return (digit - 1);
}

int	power_of_ten(char pow)
{
	int	power;

	power = 1;
	while (pow > 0)
	{
		power *= 10;
		pow --;
	}
	return (power);
}
