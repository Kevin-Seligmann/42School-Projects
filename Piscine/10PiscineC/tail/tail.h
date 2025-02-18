/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:39:11 by kseligma          #+#    #+#             */
/*   Updated: 2024/09/05 02:42:19 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAIL_H
# define TAIL_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>

typedef struct s_tail
{
	size_t	bytes_read;
	bool	err;
	char	*tail_buffer;
	char	*filename;
	int		args_consumed;
	int		args_count;
	int		fd;
	size_t	tail_size;
}	t_tail;

int		ft_strlen(char *str);
int		parse_argv(int argc, char **argv, size_t *tail_size, int *arg_count);
int		print_error(char *pre_err, char *err_str, char err_b, char *post_err);
int		print_error_2(char *s1, char *arg, char *s3, char *s4);
int		syscall_error(t_tail *data);
void	print_tails(t_tail *data, char **argv);

#endif
