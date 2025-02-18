/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:05:44 by kseligma          #+#    #+#             */
/*   Updated: 2023/11/04 17:05:45 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		ft_atoi(char *str);
int		str_is_nbr(char *inp);
void	rush02(int nbr, char *f);
int		ft_atoi(char *str);

int	main(int argc, char **argv)
{
	if (argc < 2)
		write(1, "Error", 5);
	else if (argc == 2)
	{
		if (!str_is_nbr(argv[1]))
			write(1, "Error", 5);
		else
			rush02(ft_atoi(argv[1]), "numbers.dict");
	}
	else
	{
		if (!str_is_nbr(argv[2]))
			write(1, "Error", 5);
		else
			rush02(ft_atoi(argv[2]), argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}

int	str_is_nbr(char *str)
{
	while (*str != 0)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str ++;
	}
	return (1);
}
