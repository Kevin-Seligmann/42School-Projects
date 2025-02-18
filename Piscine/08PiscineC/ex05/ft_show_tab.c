/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:36:44 by kseligma          #+#    #+#             */
/*   Updated: 2023/11/06 15:36:52 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_stock_str.h"

void	printstr(char *str)
{
	while (*str != 0)
	{
		write(1, str, 1);
		str ++;
	}
	write(1, "\n", 1);
}

void	ft_putnbr(int nbr)
{
	char	cnum;

	if (nbr < 10)
	{
		cnum = nbr + '0';
		write(1, &cnum, 1);
	}
	else
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	ind;

	ind = 0;
	while (par[ind].str != 0)
	{
		printstr(par[ind].str);
		ft_putnbr(par[ind].size);
		write(1, "\n", 1);
		printstr(par[ind].copy);
		ind ++;
	}
}

/*int	main(int argc, char **argv)
{
	printstr(argv[1]);
}*/
