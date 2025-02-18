/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:08:47 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/06 23:27:02 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>
#define BSIZE 30000

static size_t	ft_strlen(char *str)
{
	size_t	ind;

	if (!str)
		return (0);
	ind = 0;
	while (str[ind])
		ind ++;
	return (ind);
}

static void	write_error(char *err, char *file)
{
	write(2, "cat: ", ft_strlen("cat: "));
	write(2, file, ft_strlen(file));
	write(2, ": ", ft_strlen(": "));
	write(2, err, ft_strlen(err));
	write(2, "\n", 1);
}

static int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		write_error(strerror(errno), file);
	return (fd);
}

static int	output_from_fd(int fd, char *file)
{
	char	buffer[BSIZE];
	ssize_t	read_count;

	read_count = 1;
	while (read_count > 0)
	{
		read_count = read(fd, buffer, BSIZE);
		if (read_count < 0 || write(STDOUT_FILENO, buffer, read_count) < 0)
		{
			write_error(strerror(errno), file);
			return (-1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	size_t	ind;
	bool	error;

	if (argc == 1)
	{
		output_from_fd(STDIN_FILENO, "STDIN");
		return (EXIT_SUCCESS);
	}
	ind = 0;
	while (argv[++ind])
	{
		fd = open_file(argv[ind]);
		if (fd < 0)
		{
			error = true;
			continue ;
		}
		output_from_fd(fd, argv[ind]);
	}
	if (error)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
