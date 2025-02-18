/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:52:43 by kseligma          #+#    #+#             */
/*   Updated: 2023/10/18 20:22:09 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**/

void	ft_print_comb(void)
{
	char	list_of_numbers[600];
	int		num;
	int		ind;

	num = 0;
	ind = 0;
	while (num < 1000)
	{
		if (num / 100 < (num % 100) / 10 && (num % 100) / 10 < num % 10)
		{
			list_of_numbers[ind] = num / 100 + 48;
			list_of_numbers[ind + 1] = (num % 100) / 10 + 48;
			list_of_numbers[ind + 2] = num % 10 + 48;
			list_of_numbers[ind + 3] = 44;
			list_of_numbers[ind + 4] = 32;
			ind += 5;
		}
		num ++;
	}
	write(1, &list_of_numbers, 598);
}
