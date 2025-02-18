/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:00:18 by kseligma          #+#    #+#             */
/*   Updated: 2023/10/23 20:00:24 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>
//#include <stdlib.h>

void	write_hexa(unsigned long long dec, int size);

void	ft_putstr_non_printable(char *str)
{
	int	ind;

	ind = 0;
	while (str[ind] != 0)
	{
		if (str[ind] < 32 || str[ind] > 126)
			write_hexa(str[ind], 2);
		else
			write(1, &str[ind], 1);
		ind ++;
	}
}

void	write_hexa(unsigned long long dec, int size)
{
	char				hex[16];
	unsigned long long	rem;
	int					ind;

	ind = 0;
	while (ind < 16)
	{
		rem = dec % 16;
		if (rem < 10)
			rem += 48;
		else
			rem += 87;
		hex[16 - ind] = rem;
		dec /= 16;
		ind ++;
	}
	write(1, "\\", 1);
	write(1, &hex[16 - size + 1], size);
}

/*int	main(int argc, char *argv[])
{
	argc = 0;
	printf("\n El hexa de %s es>", argv[1]);
	write_hexa(argv[1][0], 2);
	return (0);
}*/
