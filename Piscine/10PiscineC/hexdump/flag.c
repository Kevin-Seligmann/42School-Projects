/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:01:53 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/10 02:28:57 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

bool	is_flag(char *str)
{
	return (str[0] == '-' && str[1] != 0);
}

int	read_flags(int argc, char **argv, t_hexdump *hex)
{
	int		ind;
	size_t	str_ind;

	ind = 0;
	while (++ind < argc)
	{
		if (is_flag(argv[ind]))
		{
			str_ind = 0;
			while (argv[ind][++str_ind] == 'C')
				hex->canonical_flag_count ++;
			if (argv[ind][str_ind] != 0)
			{
				print_invalid_option(argv[ind][str_ind]);
				return (-1);
			}
		}
		else
			hex->args_count ++;
	}
	return (0);
}
