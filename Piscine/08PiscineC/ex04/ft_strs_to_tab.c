/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:06:21 by kseligma          #+#    #+#             */
/*   Updated: 2023/11/06 15:06:23 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*strcopy(char *str, int len);
int		ftstrlen(char *str);
void	ft_show_tab(struct s_stock_str *par);

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*ans;
	int			ind;
	int			len;

	ind = 0;
	ans = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (ans == 0)
		return (0);
	while (ind < ac)
	{
		len = ftstrlen(av[ind]);
		ans[ind].size = len;
		ans[ind].str = av[ind];
		ans[ind].copy = strcopy(av[ind], len);
		ind ++;
	}
	ans[ind].str = 0;
	return (ans);
}

char	*strcopy(char *str, int len)
{
	char	*ans;
	int		ind;

	ind = 0;
	ans = (char *)malloc((len + 1) * sizeof(char));
	if (ans == 0)
		return (0);
	while (ind < len)
	{
		ans[ind] = str[ind];
		ind ++;
	}
	ans[ind] = 0;
	return (ans);
}

int	ftstrlen(char *str)
{
	int	ind;

	ind = 0;
	while (str[ind] != 0)
		ind ++;
	return (ind);
}

/*void	printstr(char *str)
{
	while(*str != 0)
	{
		write(1, str, 1);
		str ++;
	}
	write(1, "\n", 1);
}

void ft_putnbr(int	nbr)
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
	while(par[ind].str != 0)
	{
		printstr(par[ind].str);
		ft_putnbr(par[ind].size);
		write(1, "\n", 1);
		printstr(par[ind].copy);
		ind ++;
	}
}

int	main(int argc, char **argv)
{
	struct s_stock_str *ans;
	int ind;

	ans = ft_strs_to_tab(argc - 1, &argv[1]);
	ft_show_tab(ft_strs_to_tab(argc - 1, &argv[1]));
	ind = 0;
	while(ind < argc-1)
	{
		free(ans[ind].copy);
		ind ++;
	}
	free(ans);
}*/
