/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:23:30 by kseligma          #+#    #+#             */
/*   Updated: 2024/09/05 02:44:47 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

static int	print_error_help(char *pre_err, char *err_str, \
char err_b, char *post_err)
{
	print_error(pre_err, err_str, err_b, post_err);
	write(STDERR_FILENO, "Try 'tail --help' for more information.\n", \
	ft_strlen("Try 'tail --help' for more information.\n"));
	return (-1);
}

static bool	is_num(char *num)
{
	while (*num)
	{
		if (*num < '0' || *num > '9')
			return (false);
		num ++;
	}
	return (true);
}

static int	tailtoi(char *num, size_t *tail_size)
{
	size_t	res;
	size_t	prev;

	res = 0;
	while (*num)
	{
		prev = res;
		res = res * 10 + *num - '0';
		if (res < prev)
			return (-1);
		num ++;
	}
	*tail_size = res;
	return (0);
}

static int	parse_c_flag(int *ind, int argc, char **argv, size_t *tail_size)
{
	char	*num;

	if (argv[*ind][2])
		num = &(argv[*ind][2]);
	else
	{
		(*ind)++;
		if (*ind == argc)
			return (print_error_help("option requires an argument -- ", \
			"c", 0, 0));
		num = argv[*ind];
	}
	if (num[0] == '-')
		num ++;
	if (!is_num(num))
		return (print_error("invalid number of bytes: ", num, 0, 0));
	if (tailtoi(num, tail_size) == -1)
		return (print_error("invalid number of bytes: ", num, 0, \
		"Value too large for defined data type"));
	return (0);
}

int	parse_argv(int argc, char **argv, size_t *tail_size, int *arg_count)
{
	int	ind;

	*arg_count = 0;
	*tail_size = 0;
	ind = 1;
	while (ind < argc)
	{
		if (argv[ind][0] == '-' && argv[ind][1] == 'c' && \
		parse_c_flag(&ind, argc, argv, tail_size) == -1)
			return (-1);
		else if (argv[ind][0] == '-' && argv[ind][1])
		{
			if (argv[ind][1] >= '0' && argv[ind][1] <= '9')
				return (print_error("option used in invalid context -- ", \
				0, argv[ind][1], 0));
			else
				return (print_error_help("invalid option -- ", \
				0, argv[ind][1], 0));
		}
		else
			(*arg_count)++;
		ind ++;
	}
	return (0);
}
