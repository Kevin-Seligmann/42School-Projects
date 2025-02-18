/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:38:30 by kseligma          #+#    #+#             */
/*   Updated: 2024/01/17 17:06:32 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	count;

	if (dst > src)
	{
		count = 0;
		while (count < len)
		{
			((char *) dst)[len - count - 1] = ((char *) src)[len - count - 1];
			count ++;
		}
	}
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}
