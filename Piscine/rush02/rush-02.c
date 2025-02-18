/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:20:01 by kseligma          #+#    #+#             */
/*   Updated: 2023/11/04 16:20:02 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*select_file(char *f);
int		ft_atoi(char *str);
int		biggest_lt_nbr(int nb);
char	*ft_putnbr(int nb, char dest[11]);
char	*find(char *digit, char *dict);
void	print_20_100(int nbr, char *file, char *dest);
void	print_100_plus(int nbr, char *file, char *f, char *dest);

void	rush02(int nbr, char *f)
{
	char	*file;
	char	dest[11];

	file = select_file(f);
	if (*file == 0)
	{
		write(1, "Dict Error", 10);
		return ;
	}
	if (nbr < 20)
		find(ft_putnbr(nbr, dest), file);
	else if (nbr < 100)
		print_20_100(nbr, file, dest);
	else
		print_100_plus(nbr, file, f, dest);
	free(file);
}

void	print_20_100(int nbr, char *file, char *dest)
{
	find(ft_putnbr((nbr / 10) * 10, dest), file);
	if (nbr % 10 != 0)
	{
		write(1, "-", 1);
		find(ft_putnbr(nbr % 10, dest), file);
	}
}

void	print_100_plus(int nbr, char *file, char *f, char *dest)
{
	int	bln;

	bln = biggest_lt_nbr(nbr);
	rush02(nbr / bln, f);
	write(1, " ", 1);
	find(ft_putnbr(bln, dest), file);
	if (nbr % bln != 0)
	{
		write(1, " ", 1);
		rush02(nbr % bln, f);
	}
}

int	biggest_lt_nbr(int nb)
{
	if (nb >= 1000000000)
		return (1000000000);
	if (nb >= 1000000)
		return (1000000);
	if (nb >= 1000)
		return (1000);
	if (nb >= 100)
		return (100);
	if (nb >= 20)
		return ((nb / 10) * 10);
	return (nb);
}

/*int	main(int argc, char **argv)
{
	rush02(ft_atoi(argv[1]), "numbers.dict");
	return (0);
}*/
