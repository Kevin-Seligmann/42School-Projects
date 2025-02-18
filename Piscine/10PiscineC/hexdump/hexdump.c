/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 01:36:51 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/10 17:26:32 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

static void	manage_new_buffer_flag(t_hexdump *hex)
{
	hex->prev_buffer_was_different = hex->new_buffer_is_different;
	hex->new_buffer_is_different = false;
}

static void	write_total_bytes_read(t_hexdump *hex)
{
	fill_counter_buffer(hex);
	hex->counter_buffer[hex->counter_buffer_ind ++] = '\n';
	write(STDOUT_FILENO, hex->counter_buffer, hex->counter_buffer_ind);
}

static void	write_line(t_hexdump *hex)
{
	unsigned int	i;

	if (!hex->new_buffer_is_different && hex->prev_buffer_was_different)
		write(STDOUT_FILENO, &"*\n", 2);
	if (!hex->new_buffer_is_different)
		return ;
	hex->full_buff_ind = 0;
	put_counter_in_buffer(hex);
	pad_buffer(hex, hex->pre_line_margin);
	put_line_in_buffer(hex);
	pad_buffer(hex, hex->post_line_margin);
	if (hex->canonical_flag_count > 0)
		put_rawline_in_buffer(hex);
	hex->full_buff[hex->full_buff_ind ++] = '\n';
	i = 0;
	while (1)
	{
		if (write(STDOUT_FILENO, hex->full_buff, hex->full_buff_ind) < 0)
			print_error(hex, "Writting", strerror(errno));
		i ++;
		if (hex->canonical_flag_count == 0 || i == hex->canonical_flag_count)
			break ;
	}
}

static void	dump(int argc, char **argv, t_hexdump *hex)
{
	char	c;

	fill_counter_buffer(hex);
	while (get_next_byte(hex, argc, argv, &c) != -1)
	{
		if (hex->line_buffer[hex->buffer_ind] != c)
			hex->new_buffer_is_different = true;
		hex->line_buffer[hex->buffer_ind] = c;
		hex->buffer_ind ++;
		if (hex->buffer_ind == 16)
		{
			write_line(hex);
			hex->buffer_ind = 0;
			hex->counter_buffer_ind = 0;
			put_itox_in_buffer(hex->bytes_read, hex->min_counter_size, \
			hex->counter_buffer, &hex->counter_buffer_ind);
			manage_new_buffer_flag(hex);
		}
	}
	if (hex->buffer_ind > 0)
	{
		hex->new_buffer_is_different = true;
		write_line(hex);
	}
	write_total_bytes_read(hex);
}

int	main(int argc, char **argv)
{
	static t_hexdump	hex;

	if (read_flags(argc, argv, &hex) == -1)
		return (EXIT_FAILURE);
	set_dumping_variables(&hex);
	dump(argc, argv, &hex);
	if (hex.error == true)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
