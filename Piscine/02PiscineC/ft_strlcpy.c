/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:49:49 by kseligma          #+#    #+#             */
/*   Updated: 2023/10/23 19:50:01 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdlib.h>
//#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	ind;
	unsigned int	length_s;

	length_s = 0;
	while (src[length_s] != 0)
		length_s ++;
	if (size == 0)
		return (length_s);
	ind = 0;
	while (ind < size - 1 && src[ind] != 0)
	{
		dest[ind] = src[ind];
		ind ++;
	}
	if (size > 0)
		dest[ind] = '\0';
	return (length_s);
}

/*int	main(int argc, char *argv[])
{
	char arr[100];
	argc = 0;
	ft_strlcpy(arr, argv[1], atoi(argv[2]));
	return (0);
}*/
