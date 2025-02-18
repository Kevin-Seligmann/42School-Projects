/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus_minus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:53:30 by kseligma          #+#    #+#             */
/*   Updated: 2023/11/09 13:53:31 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funct.h"

void	plus(int a, int b)
{
	ft_putnbr(a + b);
	write(1, "\n", 1);
}

void	minus(int a, int b)
{
	ft_putnbr(a - b);
	write(1, "\n", 1);
}
