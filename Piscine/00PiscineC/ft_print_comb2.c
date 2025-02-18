/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:38:02 by kseligma          #+#    #+#             */
/*   Updated: 2023/10/19 15:55:18 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	int		num;
	char	list_of_numbers[57324];
	int		ind;

	num = 0;
	ind = 0;
	while (num < 10000)
	{
		if (num / 100 < num % 100)
		{
			list_of_numbers[ind] = num / 1000 + 48;
			list_of_numbers[ind + 1] = num % 1000 / 100 + 48;
			list_of_numbers[ind + 2] = 32;
			list_of_numbers[ind + 3] = num % 100 / 10 + 48;
			list_of_numbers[ind + 4] = num % 10 + 48;
			list_of_numbers[ind + 5] = 44;
			list_of_numbers[ind + 6] = 32;
			ind += 7;
		}
		num ++;
	}
	write(1, &list_of_numbers, 34648);
}
