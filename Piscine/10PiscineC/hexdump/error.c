/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:54:09 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/10 17:26:18 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

void	print_invalid_option(char c)
{
	write(STDERR_FILENO, "hexdump: invalid option -- ", \
	ft_strlen("hexdump: invalid option -- "));
	write(STDERR_FILENO, "\'", 1);
	write(STDERR_FILENO, &c, 1);
	write(STDERR_FILENO, "\'\n", 2);
	write(STDERR_FILENO, "Try 'hexdump --help' for more information.", \
	ft_strlen("Try 'hexdump --help' for more information."));
	write(STDERR_FILENO, "\n", 1);
}

void	print_error(t_hexdump *hex, char *file, char *err)
{
	hex->error = true;
	write(2, "hexdump: ", ft_strlen("hexdump: "));
	write(2, file, ft_strlen(file));
	write(2, ": ", ft_strlen(": "));
	write(2, err, ft_strlen(err));
	write(2, "\n", 1);
}
