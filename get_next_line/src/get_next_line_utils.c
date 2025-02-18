/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 07:28:14 by kseligma          #+#    #+#             */
/*   Updated: 2024/02/12 08:43:06 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	ind;

	ind = 0;
	if (!str)
		return (0);
	while (str[ind] != 0)
		ind ++;
	return (ind);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	ind;

	ind = 0;
	ptr = (char *) malloc(count * size);
	if (ptr == 0)
		return (0);
	while (ind < count * size)
		ptr[ind++] = 0;
	return ((void *) ptr);
}

char	ft_strn(char *s, char c, size_t n)
{
	size_t	ind;

	ind = 0;
	while (ind < n || n == 0)
	{
		if (s[ind] == c)
			return (1);
		if (s[ind] == 0)
			return (0);
		ind ++;
	}
	return (0);
}

char	*manage_left(char **left, char op)
{
	char	*aux;

	if (op == 1)
	{
		aux = 0;
		if (!(*left))
		{
			aux = malloc(1);
			if (aux)
				aux[0] = 0;
			return (aux);
		}
		return (*left);
	}
	else
	{
		free (*left);
		*left = 0;
		return (0);
	}
}

void	ft_cpy(char *dst, char *src, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n)
	{
		dst[count] = src[count];
		count ++;
	}
	dst[count] = 0;
}
