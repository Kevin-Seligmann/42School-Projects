/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 01:41:58 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/10 17:26:49 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEXDUMP_H

# define HEXDUMP_H

# include <stdbool.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>

# define LINE_BUFFER_SIZE 100
# define COUNTER_BUFFER_SIZE 100

typedef struct s_hexdump
{
	size_t			bytes_read;
	size_t			buffer_ind;
	size_t			counter_buffer_ind;
	size_t			full_buff_ind;
	int				args_ind;
	int				args_count;
	char			line_buffer[LINE_BUFFER_SIZE];
	char			counter_buffer[COUNTER_BUFFER_SIZE];
	char			full_buff[LINE_BUFFER_SIZE * 2 + COUNTER_BUFFER_SIZE];
	unsigned int	canonical_flag_count;
	unsigned int	line_chunk_size;
	unsigned int	pre_line_margin;
	unsigned int	post_line_margin;
	unsigned int	min_counter_size;
	int				fd;
	bool			error;
	bool			new_buffer_is_different;
	bool			prev_buffer_was_different;
}	t_hexdump;

void	print_error(t_hexdump *hex, char *file, char *err);
void	print_invalid_option(char c);
size_t	ft_strlen(char *str);
int		read_flags(int argc, char **argv, t_hexdump *hex);
bool	is_flag(char *str);
void	put_itox_in_buffer(size_t hex, int min_size, \
char *buffer, size_t *buffer_ind);
void	set_dumping_variables(t_hexdump *hex);
int		get_next_byte(t_hexdump *hex, int argc, char **argv, char *c);
void	put_counter_in_buffer(t_hexdump *hex);
void	pad_buffer(t_hexdump *hex, unsigned int padsize);
void	put_line_in_buffer(t_hexdump *hex);
void	put_rawline_in_buffer(t_hexdump *hex);
void	fill_counter_buffer(t_hexdump *hex);
bool	is_print(char c);

#endif
