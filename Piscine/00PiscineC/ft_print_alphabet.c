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

void	ft_print_alphabet(void)
{
	char	alphabet[26];
	char	letter;
	int		ind;

	letter = 97;
	ind = 0;
	while (letter < 123)
	{
		alphabet[ind] = letter;
		letter ++;
		ind ++;
	}
	write(1, &alphabet, 26);
}
