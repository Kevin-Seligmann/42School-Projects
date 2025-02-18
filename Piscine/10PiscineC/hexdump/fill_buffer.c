/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 03:35:43 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/10 17:26:02 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

void	put_counter_in_buffer(t_hexdump *hex)
{
	while (hex->full_buff_ind < hex->counter_buffer_ind)
	{
		hex->full_buff[hex->full_buff_ind] = \
		hex->counter_buffer[hex->full_buff_ind];
		hex->full_buff_ind ++;
	}
}

void	pad_buffer(t_hexdump *hex, unsigned int padsize)
{
	while (padsize > 0)
	{
		hex->full_buff[hex->full_buff_ind] = ' ';
		hex->full_buff_ind ++;
		padsize --;
	}
}

void	put_line_in_buffer(t_hexdump *hex)
{
	size_t	aux;

	aux = 0;
	while (aux < 16)
	{
		if (aux < hex->buffer_ind)
			put_itox_in_buffer(hex->line_buffer[aux], 2, \
			hex->full_buff, &hex->full_buff_ind);
		else
			pad_buffer(hex, 2);
		if ((aux != 15 && (aux + 1) % hex->line_chunk_size == 0))
			pad_buffer(hex, 1);
		if ((hex->canonical_flag_count > 0 && aux == 7))
			pad_buffer(hex, 1);
		aux ++;
	}
}

void	put_rawline_in_buffer(t_hexdump *hex)
{
	size_t	ind;

	ind = 0;
	hex->full_buff[hex->full_buff_ind++] = '|';
	while (ind < hex->buffer_ind)
	{
		if (is_print(hex->line_buffer[ind]))
			hex->full_buff[hex->full_buff_ind] = hex->line_buffer[ind];
		else
			hex->full_buff[hex->full_buff_ind] = '.';
		hex->full_buff_ind ++;
		ind ++;
	}
	hex->full_buff[hex->full_buff_ind++] = '|';
}

void	fill_counter_buffer(t_hexdump *hex)
{
	hex->counter_buffer_ind = 0;
	put_itox_in_buffer(hex->bytes_read, hex->min_counter_size, \
	hex->counter_buffer, &hex->counter_buffer_ind);
}
