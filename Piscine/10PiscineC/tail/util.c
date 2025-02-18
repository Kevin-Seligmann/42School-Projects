/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:44:36 by kseligma          #+#    #+#             */
/*   Updated: 2024/09/05 02:45:48 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

int	ft_strlen(char *str)
{
	int	ind;

	ind = 0;
	while (str[ind])
		ind ++;
	return (ind);
}

int	print_error(char *pre_err, char *err_str, char err_b, char *post_err)
{
	write(STDERR_FILENO, "tail: ", ft_strlen("tail: "));
	if (pre_err)
		write(STDERR_FILENO, pre_err, ft_strlen(pre_err));
	write(STDERR_FILENO, "'", 1);
	if (err_str)
		write(STDERR_FILENO, err_str, ft_strlen(err_str));
	if (err_b)
		write(STDERR_FILENO, &err_b, 1);
	write(STDERR_FILENO, "'", 1);
	if (post_err)
	{
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, post_err, ft_strlen(post_err));
	}
	write(STDERR_FILENO, "\n", 1);
	return (-1);
}

int	print_error_2(char *s1, char *arg, char *s3, char *s4)
{
	write(STDERR_FILENO, "tail: ", ft_strlen("tail: "));
	write(STDERR_FILENO, s1, ft_strlen(s1));
	write(STDERR_FILENO, "\'", 1);
	write(STDERR_FILENO, arg, ft_strlen(arg));
	write(STDERR_FILENO, "\'", 1);
	write(STDERR_FILENO, s3, ft_strlen(s3));
	write(STDERR_FILENO, s4, ft_strlen(s4));
	write(STDERR_FILENO, "\n", 1);
	return (-1);
}

int	syscall_error(t_tail *data)
{
	data->err = true;
	return (print_error(0, data->filename, 0, strerror(errno)));
}
