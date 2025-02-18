/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_byte.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 02:44:59 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/10 02:54:03 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

static int	open_next_file(t_hexdump *hex, int argc, char **argv)
{
	while (hex->args_ind < argc)
	{
		if (!is_flag(argv[hex->args_ind]))
		{
			if (hex->fd > -1)
				close (hex->fd);
			hex->fd = open(argv[hex->args_ind], O_RDONLY);
			if (hex->fd < 0)
				print_error(hex, argv[hex->args_ind], strerror(errno));
			else
			{
				hex->args_ind ++;
				return (0);
			}
		}
		hex->args_ind ++;
	}
	return (-1);
}

int	get_next_byte(t_hexdump *hex, int argc, char **argv, char *c)
{
	int	bytes_read;

	bytes_read = 0;
	while (1)
	{
		if (hex->fd > -1)
			bytes_read = read(hex->fd, c, 1);
		if (bytes_read == 1)
		{
			hex->bytes_read ++;
			return (0);
		}
		else if (bytes_read < 0)
		{
			print_error(hex, "writting", strerror(errno));
			return (-1);
		}
		if (open_next_file(hex, argc, argv) == -1)
			return (-1);
	}
}
