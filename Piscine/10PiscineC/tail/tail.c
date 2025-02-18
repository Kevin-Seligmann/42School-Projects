/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:52:37 by kseligma          #+#    #+#             */
/*   Updated: 2024/09/05 02:41:09 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

int	main(int argc, char **argv)
{
	static t_tail	data;

	if (parse_argv(argc, argv, &data.tail_size, &data.args_count) == -1)
		return (EXIT_FAILURE);
	if (data.tail_size == 0)
		return (EXIT_SUCCESS);
	data.tail_buffer = malloc(data.tail_size * sizeof(char));
	if (!data.tail_buffer)
	{
		print_error(0, "memory error", 0, 0);
		return (EXIT_FAILURE);
	}
	print_tails(&data, argv);
	free(data.tail_buffer);
	if (data.err)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
