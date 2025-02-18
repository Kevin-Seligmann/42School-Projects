/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mults.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:54:19 by kseligma          #+#    #+#             */
/*   Updated: 2023/11/09 13:54:20 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funct.h"

void	ftmod(int a, int b)
{
	if (b == 0)
		write(1, "Stop: modulo by zero", 20);
	else
		ft_putnbr(a % b);
	write(1, "\n", 1);
}

void	fttimes(int a, int b)
{
	ft_putnbr(a * b);
	write(1, "\n", 1);
}

void	ftdiv(int a, int b)
{
	if (b == 0)
		write(1, "Stop: division by zero", 22);
	else
		ft_putnbr(a / b);
	write(1, "\n", 1);
}
