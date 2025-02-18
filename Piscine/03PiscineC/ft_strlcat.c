/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:10:09 by kseligma          #+#    #+#             */
/*   Updated: 2023/10/25 15:14:53 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	length_calc(char *src);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	ind1;
	unsigned int	ind2;
	unsigned int	len_dest;
	unsigned int	len_src;

	len_dest = length_calc(dest);
	len_src = length_calc(src);
	ind1 = 0;
	ind2 = 0;
	if (size < len_dest)
		return (size + len_src);
	while (dest[ind1] != 0)
		ind1 ++;
	while (src[ind2] != 0 && ind2 + len_dest < size - 1)
	{
		dest[ind1 + ind2] = src[ind2];
		ind2 ++;
	}
	dest[ind1 + ind2] = 0;
	return (len_dest + len_src);
}

unsigned int	length_calc(char *src)
{
	unsigned int	length;

	length = 0;
	while (src[length] != 0)
		length ++;
	return (length);
}
