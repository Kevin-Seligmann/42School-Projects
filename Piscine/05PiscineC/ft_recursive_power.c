/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:06:01 by kseligma          #+#    #+#             */
/*   Updated: 2023/10/29 19:06:08 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

/*int	main(int argc, char *argv[])
{
	argc = 0;
	printf(" %d a la %d es %d",
	atoi(argv[1]),
	atoi(argv[2]),
	ft_recursive_power(atoi(argv[1]), atoi(argv[2])));
}*/
