/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:51:41 by kseligma          #+#    #+#             */
/*   Updated: 2023/10/31 17:51:42 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <unistd.h>

char	*ft_strdup(char *src)
{
	unsigned int	ind;
	char			*strcpy;

	ind = 0;
	while (src[ind] != 0)
		ind ++;
	strcpy = (char *) malloc(ind);
	if (strcpy == NULL)
		return (NULL);
	ind = 0;
	while (src[ind] != 0)
	{
		strcpy[ind] = src[ind];
		ind ++;
	}
	strcpy[ind] = 0;
	return (strcpy);
}

/*int	main(int argc, char *argv[])
{
	argc = 0;
	ft_strdup(argv[1]);
	return (0);
}*/
