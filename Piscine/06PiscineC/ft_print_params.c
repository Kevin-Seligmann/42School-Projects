/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:10:39 by kseligma          #+#    #+#             */
/*   Updated: 2023/10/30 19:10:40 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	ind;
	int	ind2;

	ind2 = 1;
	while (ind2 < argc)
	{
		ind = 0;
		while (argv[ind2][ind] != 0)
		{
			write(1, &argv[ind2][ind], 1);
			ind ++;
		}
		write(1, "\n", 1);
		ind2 ++;
	}
	return (0);
}
