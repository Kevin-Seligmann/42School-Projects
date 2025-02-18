/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:54:03 by kseligma          #+#    #+#             */
/*   Updated: 2023/10/30 15:54:06 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	next_column(char *status, int size, int count);
int	not_valid(char *status, int size, char val);

int	ft_ten_queens_puzzle(void)
{
	char	status[11];

	return (next_column(&status[0], 1, 0));
}

int	next_column(char *status, int size, int count)
{
	char	val;

	val = '0';
	while (val < '0' + 10)
	{
		if (not_valid(status, size, val))
		{
			val ++;
		}
		else
		{
			status[size] = val;
			if (size == 10)
			{
				count ++;
				write(1, &status[1], 10);
				write(1, "\n", 1);
				if (val == 9)
					return (count);
			}
			count = next_column(status, size + 1, count);
			val ++;
		}
	}
	return (count);
}

int	not_valid(char *status, int size, char val)
{
	int	ind;

	ind = 1;
	while (size > 1)
	{
		if (val == status[size - 1])
			return (1);
		if (val == status[size - 1] + ind || val == status[size - 1] - ind)
			return (1);
		ind ++;
		size --;
	}
	return (0);
}

/*int	main(void)
{
	ft_ten_queens_puzzle();
	return (0);
}*/
