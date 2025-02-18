/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:56:17 by kseligma          #+#    #+#             */
/*   Updated: 2024/01/17 16:51:09 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memchr(const void *s, int c, size_t n)
{
	char	l;
	char	*ptr;
	size_t	count;

	ptr = (char *) s;
	l = (unsigned char) c;
	if (n == 0)
		return (0);
	count = 0;
	while (*ptr != l)
	{
		ptr ++;
		count ++;
		if (count == n)
			return (0);
	}
	if (*ptr == l && n > 0)
		return (ptr);
	return (0);
}
