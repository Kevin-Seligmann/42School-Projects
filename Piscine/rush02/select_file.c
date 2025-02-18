/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:51:53 by kseligma          #+#    #+#             */
/*   Updated: 2023/11/04 16:51:55 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

char				*select_file(char *f);
unsigned long long	file_size(char *file);

char	*select_file(char *f)
{
	unsigned long long	f_len;
	char				*dict;
	int					oo;
	int					ro;

	oo = open(f, 0);
	f_len = file_size(f);
	dict = (char *)malloc(f_len + 1);
	dict[0] = '\n';
	if (oo == -1 || f_len == 0 || dict == 0)
		return ("");
	ro = read(oo, dict + 1, f_len);
	if (ro == -1)
		return ("");
	close(oo);
	return (dict);
}

unsigned long long	file_size(char *file)
{
	unsigned long long	size;
	char				*f;
	int					oo;
	int					ro;

	f = (char *)malloc(1);
	oo = open(file, 0);
	ro = 1;
	size = 0;
	if (f == 0 || oo == -1)
		return (0);
	while (ro != 0)
	{
		ro = read(oo, f, 1);
		size ++;
	}
	close(oo);
	free (f);
	return (size);
}

/*int	main(int argc, char **argv)
{
	if (argc > 1)
		printf("File %s \n", select_file(argv[2]));
	return (0);
}*/
