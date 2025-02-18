/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:34:19 by kseligma          #+#    #+#             */
/*   Updated: 2024/01/13 19:55:10 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
