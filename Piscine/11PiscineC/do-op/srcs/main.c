/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:42:43 by kseligma          #+#    #+#             */
/*   Updated: 2023/11/09 13:42:45 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funct.h"

int	main(int argc, char **argv)
{
	int		a;
	int		b;
	void	(*f[5])(int a, int b);

	f[0] = plus;
	f[1] = minus;
	f[2] = ftdiv;
	f[3] = fttimes;
	f[4] = ftmod;
	if (argc != 4)
		return (0);
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	operation(f, a, b, argv);
	return (0);
}

void	operation(void (*f[5])(int a, int b), int a, int b, char **argv)
{
	if (argv[2][0] == '+' && argv[2][1] == 0)
		f[0](a, b);
	else if (argv[2][0] == '-' && argv[2][1] == 0)
		f[1](a, b);
	else if (argv[2][0] == '/' && argv[2][1] == 0)
		f[2](a, b);
	else if (argv[2][0] == '*' && argv[2][1] == 0)
		f[3](a, b);
	else if (argv[2][0] == '%' && argv[2][1] == 0)
		f[4](a, b);
	else
	{
		ft_putnbr(0);
		write(1, "\n", 1);
	}
}
