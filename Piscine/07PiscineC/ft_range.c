/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:22:32 by kseligma          #+#    #+#             */
/*   Updated: 2023/10/31 18:22:33 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	ind;

	ind = 0;
	arr = (int *)malloc((max - min) * sizeof(int));
	if (arr == 0 || min >= max)
		return (0);
	while (min < max)
	{
		arr[ind] = min;
		min ++;
		ind ++;
	}
	return (arr);
}

/*int main(int argc, char *argv[])
{
	int loop;
	int *array = ft_range(atoi(argv[1]), atoi(argv[2]));
    for(loop = 0; loop < (atoi(argv[2]) - atoi(argv[1])); loop++)
    	printf("%d ", array[loop]);
   return (0);
}*/
