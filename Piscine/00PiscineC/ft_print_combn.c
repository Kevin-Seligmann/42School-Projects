/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:04:21 by kseligma          #+#    #+#             */
/*   Updated: 2023/10/19 19:19:29 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		power_of_ten(char exp);
char	valid_number(char size, int number, int divisor);
void	write_number(char size, int number, int divisor);
void	write_after_number(int number, int max_number);

void	ft_print_combn(int n)
{
	int		number;
	int		divisor;
	int		max_number;
	int		size;

	size = n;
	max_number = 0;
	while (size > 0)
	{
		max_number += (10 - size) * power_of_ten(size - 1);
		size --;
	}
	divisor = power_of_ten(n - 1);
	number = 0;
	while (number < max_number + 1)
	{
		if (valid_number(n, number, divisor) == 1)
		{
			write_number(n, number, divisor);
			write_after_number(number, max_number);
		}
		number ++;
	}
}

int	power_of_ten(char exp)
{
	int	power;

	power = 1;
	while (exp > 0)
	{
		power *= 10;
		exp --;
	}
	return (power);
}

void	write_number(char size, int number, int divisor)
{
	char	number_string[9];
	int		ind;
	int		digit;

	ind = 0;
	digit = size;
	while (digit > 0)
	{
		number_string[ind] = number / divisor + 48;
		number -= (number / divisor) * divisor;
		divisor /= 10;
		digit --;
		ind ++;
	}
	write (1, &number_string, size);
}

void	write_after_number(int number, int max_number)
{
	char	line_skip;

	line_skip = 10;
	if (number < max_number)
	{
		write(1, ",", 1);
		write(1, " ", 1);
	}
}

char	valid_number(char size, int number, int divisor)
{
	while (size > 1)
	{
		if (number / divisor >= number % divisor / (divisor / 10))
		{
			return (0);
		}
		number -= divisor * (number / divisor);
		divisor /= 10;
		size --;
	}
	return (1);
}
