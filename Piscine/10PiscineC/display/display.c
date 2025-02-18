/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:20:25 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/06 22:04:54 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define BSIZE 10

static int	display_file(int fd)
{
	char	buffer[BSIZE];
	ssize_t	read_count;

	read_count = 1;
	while (read_count > 0)
	{
		read_count = read(fd, buffer, BSIZE);
		if (read_count < 0)
			return (-1);
		if (write(STDOUT_FILENO, buffer, read_count) == -1)
			return (-1);
	}
	return (0);
}

static int	check_arguments(int argc)
{
	if (argc == 1)
	{
		write(STDERR_FILENO, "File name missing.\n", 19);
		return (-1);
	}
	if (argc > 2)
	{
		write(STDERR_FILENO, "Too many arguments.\n", 20);
		return (-1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	fd;

	if (check_arguments(argc) == -1)
		return (EXIT_FAILURE);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(STDERR_FILENO, "Cannot read file.\n", 18);
		return (EXIT_FAILURE);
	}
	if (display_file(fd) == -1)
	{
		write(STDERR_FILENO, "Cannot read file.\n", 18);
		close(fd);
		return (EXIT_FAILURE);
	}
	close(fd);
	return (EXIT_SUCCESS);
}
