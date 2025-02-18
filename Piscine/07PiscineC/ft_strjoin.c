/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:46:52 by kseligma          #+#    #+#             */
/*   Updated: 2023/10/31 19:46:54 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		str_len(char *str);
void	ft_append(char **str1, char *str2);
int		alloc_size(int size, char **strs, char *sep);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		ind;
	char	*str;
	int		all_size;

	ind = 0;
	if (size == 0)
	{
		str = (char *)malloc(1);
		str[0] = 0;
		return (str);
	}
	all_size = alloc_size(size, strs, sep);
	str = (char *)malloc(all_size);
	while (ind < all_size)
		str[ind++] = 0;
	ind = 0;
	while (ind < size - 1)
	{
		ft_append(&str, strs[ind]);
		ft_append(&str, sep);
		ind ++;
	}
	ft_append(&str, strs[ind]);
	return (str);
}

int	alloc_size(int size, char **strs, char *sep)
{
	int		alloc_size;
	int		ind;

	ind = 0;
	alloc_size = 0;
	alloc_size += str_len(sep) * (size - 1);
	while (ind < size)
	{
		alloc_size += str_len(strs[ind]);
		ind ++;
	}
	return (alloc_size + 1);
}

int	str_len(char *str)
{
	int	ind;

	ind = 0;
	while (str[ind] != 0)
		ind ++;
	return (ind);
}

void	ft_append(char **str1, char *str2)
{
	int		ind;
	int		ind2;

	ind = 0;
	ind2 = 0;
	while (str1[0][ind] != 0)
		ind ++;
	while (str2[ind2] != 0)
	{
		str1[0][ind] = str2[ind2];
		ind2 ++;
		ind ++;
	}
	str1[0][ind] = 0;
}

/*int	main(int argc, char *argv[])
{
	char *strs[] = {"abc", ""};
	char *result = ft_strjoin(2, strs, ".-_");

	printf("%s\n", result);
	return (0);
}
*/
