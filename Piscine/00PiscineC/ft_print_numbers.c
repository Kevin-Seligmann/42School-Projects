/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:41:36 by kseligma          #+#    #+#             */
/*   Updated: 2023/10/18 18:47:39 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	digits[10];
	char	digit;

	digit = 48;
	while (digit < 58)
	{
		digits[digit - 48] = digit;
		digit ++;
	}
	write(1, &digits, 10);
}
