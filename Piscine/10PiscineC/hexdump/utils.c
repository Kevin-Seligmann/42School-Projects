/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 01:12:22 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/10 17:27:26 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

bool	is_print(char c)
{
	return (c >= ' ' && c <= '~');
}

void	put_itox_in_buffer(size_t hex, int min_size, \
char *buffer, size_t *buffer_ind)
{
	if ((min_size <= 0 && hex == 0) || *buffer_ind == LINE_BUFFER_SIZE)
		return ;
	put_itox_in_buffer(hex / 16, min_size - 1, buffer, buffer_ind);
	buffer[*buffer_ind] = "0123456789abcdef"[hex % 16];
	(*buffer_ind)++;
}

size_t	ft_strlen(char *str)
{
	size_t	ind;

	if (!str)
		return (0);
	ind = 0;
	while (str[ind])
		ind ++;
	return (ind);
}

void	set_dumping_variables(t_hexdump *hex)
{
	hex->args_ind = 1;
	if (hex->canonical_flag_count > 0)
	{
		hex->line_chunk_size = 1;
		hex->pre_line_margin = 2;
		hex->post_line_margin = 2;
		hex->min_counter_size = 8;
	}
	else
	{
		hex->line_chunk_size = 2;
		hex->pre_line_margin = 1;
		hex->post_line_margin = 0;
		hex->min_counter_size = 7;
	}
	if (hex->args_count == 0)
		hex->fd = STDIN_FILENO;
	else
		hex->fd = -1;
	hex->new_buffer_is_different = true;
}
