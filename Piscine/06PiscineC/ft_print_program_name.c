/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:00:40 by kseligma          #+#    #+#             */
/*   Updated: 2023/10/30 19:00:42 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	ind;

	ind = 0;
	argc = 0;
	while (argv[0][ind] != 0)
	{
		write(1, &argv[0][ind], 1);
		ind ++;
	}
	write(1, "\n", 1);
	return (0);
}
