/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabou-me <zabou-me@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:27:14 by zabou-me          #+#    #+#             */
/*   Updated: 2023/11/04 15:29:00 by zabou-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_putnbr(int nb, char dest[11])
{
	int		ind;

	ind = 9;
	if (nb == 0)
	{
		dest[0] = '0';
		dest[1] = 0;
		return (dest);
	}
	while (nb > 0)
	{
		dest[ind] = nb % 10 + '0';
		nb /= 10;
		ind --;
	}
	return (&dest[ind + 1]);
}

/*int	main(int argc, char **argv)
{
	char	*num;
	char 	dest[11];

	num = ft_putnbr(atoi(argv[1]), dest);
	(void)argc;
	printf("%s\n", num);
	return (0);
}*/
