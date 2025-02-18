/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tails.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 01:30:46 by kseligma          #+#    #+#             */
/*   Updated: 2024/09/05 02:45:26 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

static int	tail_to_stdout(t_tail *data)
{
	size_t	buffer_separator;

	buffer_separator = data->bytes_read % data->tail_size;
	if (data->bytes_read > data->tail_size)
		if (write(STDOUT_FILENO, data->tail_buffer + \
		buffer_separator, data->tail_size - buffer_separator) < 0)
			return (syscall_error(data));
	if (write(STDOUT_FILENO, data->tail_buffer, buffer_separator) < 0)
		return (syscall_error(data));
	return (0);
}

static int	print_filename(t_tail *data)
{
	if (data->args_consumed > 1 && write(STDOUT_FILENO, "\n", 1) < 0)
		return (syscall_error(data));
	if (write(STDOUT_FILENO, "==> ", 4) < 0)
		return (syscall_error(data));
	if (write(STDOUT_FILENO, data->filename, ft_strlen(data->filename)) < 0)
		return (syscall_error(data));
	if (write(STDOUT_FILENO, " <==\n", 5) < 0)
		return (syscall_error(data));
	return (0);
}

static void	print_file_tail(t_tail *data)
{
	ssize_t	read_output;

	data->bytes_read = 0;
	read_output = 1;
	while (read_output > 0)
	{
		read_output = read(data->fd, data->tail_buffer \
		+ data->bytes_read % data->tail_size, 1);
		data->bytes_read += read_output;
		if (read_output == 0)
			tail_to_stdout(data);
		else if (read_output < 0)
			syscall_error(data);
	}
}

static void	get_next_fd(t_tail *data, char **argv, int *ind)
{
	data->fd = -1;
	if (argv[*ind][0] == '-' && !argv[*ind][1])
	{
		data->fd = STDIN_FILENO;
		data->filename = "standard input";
		data->args_consumed ++;
	}
	else if (argv[*ind][0] != '-')
	{
		data->filename = argv[*ind];
		data->fd = open(argv[*ind], O_RDONLY);
		if (data->fd < 0)
		{
			data->err = true;
			print_error_2("cannot open ", data->filename, \
			" for reading: ", strerror(errno));
			data->args_count --;
		}
		else
			data->args_consumed ++;
	}
	if (argv[*ind][0] == '-' && argv[*ind][1] == 'c' && !argv[*ind][2])
		(*ind)++;
	(*ind)++;
}

void	print_tails(t_tail *data, char **argv)
{
	int	ind;

	ind = 1;
	data->fd = STDIN_FILENO;
	if (data->args_count == 0)
		print_file_tail(data);
	while (data->args_consumed < data->args_count)
	{
		get_next_fd(data, argv, &ind);
		if (data->fd > -1)
		{
			if (data->args_count > 1)
				print_filename(data);
			print_file_tail(data);
			close (data->fd);
		}
	}
}
