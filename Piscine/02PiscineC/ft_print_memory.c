/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:58:45 by kseligma          #+#    #+#             */
/*   Updated: 2023/10/24 15:00:38 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_hexa(unsigned long long dec, int size);
void	write_hexa_values(char *addr, char *og_addr, int size);
void	write_chars(char *addr, char *og_addr, int size);

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	ind;
	char			*mov_addr;

	ind = 0;
	mov_addr = (char *)addr;
	while ((unsigned long)mov_addr < (unsigned long long)addr + size)
	{
		write_hexa((unsigned long long) mov_addr, 16);
		write(1, ": ", 2);
		write_hexa_values(mov_addr, (char *) addr, size);
		write_chars(mov_addr, (char *) addr, size);
		mov_addr += 16;
		ind ++;
	}
	return (addr);
}

void	write_hexa_values(char *addr, char *og_addr, int size)
{
	int	ind;

	ind = 0;
	while (ind < 16)
	{
		if (addr < og_addr + size)
			write_hexa(*addr, 2);
		else
			write(1, "  ", 2);
		if (ind % 2 == 1)
			write(1, " ", 1);
		addr ++;
		ind ++;
	}
}

void	write_chars(char *addr, char *og_addr, int size)
{
	int	ind;

	ind = 0;
	while (ind < 16)
	{
		if (addr < og_addr + size)
		{
			if (*addr > 31 && *addr < 127)
				write(1, addr, 1);
			else
				write(1, ".", 1);
		}
		ind ++;
		addr ++;
	}
	write(1, "\n", 1);
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
	write(1, &hex[16 - size + 1], size);
}
