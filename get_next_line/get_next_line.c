/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 03:34:49 by kseligma          #+#    #+#             */
/*   Updated: 2024/06/23 20:36:17 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_cut(char **left, size_t lencut)
{
	size_t	len;
	char	*str;

	if (!(*left)[lencut])
		return (manage_left(left, 0));
	len = ft_strlen(*left);
	str = (char *) malloc((len - lencut + 1) * sizeof(char));
	if (!str)
		return (manage_left(left, 0));
	ft_cpy(str, *left + lencut, len - lencut);
	free(*left);
	return (str);
}

/* We find the next lineskip, str will be the function that get_next_line
returns. We also need to cut the leftovers.*/
static char	*ft_separe(char **left)
{
	char	*str;
	size_t	len;

	len = 0;
	while ((*left)[len] != 0 && (*left)[len] != '\n')
		len ++;
	if (len == 0 && !(*left)[len])
		return (manage_left(left, 0));
	if ((*left)[len] == '\n')
		len ++;
	str = malloc(len + 1);
	if (!str)
		return (manage_left(left, 0));
	ft_cpy(str, *left, len);
	*left = ft_cut(left, len);
	return (str);
}

/* Just allocating memory and copying from the previous left and buff to it.
I'm aware of this malloc call over-allocating memory */
static char	*ft_append(char *left, char *buff, ssize_t ro)
{
	char	*str;
	size_t	len_left;

	len_left = ft_strlen(left);
	str = (char *) malloc((len_left + ro + 1) * sizeof(char));
	if (!str)
		return (manage_left(&left, 0));
	ft_cpy(str, left, len_left);
	ft_cpy(str + len_left, buff, ro);
	free(left);
	return (str);
}

/* If there's no like skip, while there's no line skip or we dont reach EOF
, we read from the source appending the string to our leftover*/
static char	*readline(char *left, char *buff, int fd)
{
	ssize_t	ro;

	ro = BUFFER_SIZE;
	if (!ft_strn(left, '\n', 0))
	{
		while (ro == BUFFER_SIZE && !ft_strn(buff, '\n', ro))
		{
			ro = read(fd, buff, BUFFER_SIZE);
			if (ro < 0)
				return (manage_left(&left, 0));
			left = ft_append(left, buff, ro);
			if (!left)
				return (0);
		}
	}
	return (left);
}

/* If we read more than one line from the source, we will need to store
the leftovers on static memory, so it outlives the call of the function.

We have an array of "leftovers" to manage multiple file descriptors.
Each file descriptor is its own unique entry to this array.

manage_left will allocate a string if there's none, return the string if
there is, or free the string and set it to 0 if the flag is unset. This
was done this way due to the two file, five functions restriction.

On this function we make sure left[fd] and buff exists as
allocated memory, we make a call to the line-reading function and
we exit in case of error. Lastly, we return the result of separing
the string on the first '\n' character.*/
char	*get_next_line(int fd)
{
	static char	*left[OPEN_MAX];
	char		*buff;

	if (fd < 0 || BUFFER_SIZE < 0 || fd > OPEN_MAX)
		return (0);
	left[fd] = manage_left(&(left[fd]), 1);
	if (!left[fd])
		return (0);
	buff = (char *) calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (manage_left(&(left[fd]), 0));
	left[fd] = readline(left[fd], buff, fd);
	free(buff);
	if (!left[fd])
		return (0);
	return (ft_separe(&(left[fd])));
}
