/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:44:45 by kseligma          #+#    #+#             */
/*   Updated: 2023/10/22 14:50:09 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	alphabet[26];
	char	letter;
	int		ind;

	letter = 122;
	ind = 0;
	while (letter > 96)
	{
		alphabet[ind] = letter;
		letter --;
		ind ++;
	}
	write(1, &alphabet, 26);
}
