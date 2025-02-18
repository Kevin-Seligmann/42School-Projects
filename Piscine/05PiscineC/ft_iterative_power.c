/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:57:21 by kseligma          #+#    #+#             */
/*   Updated: 2023/10/29 18:57:24 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>

int	ft_iterative_power(int nb, int power)
{
	int	ans;

	if (power < 0)
		return (0);
	ans = 1;
	while (power > 0)
	{
		ans *= nb;
		power --;
	}
	return (ans);
}

/*int	main(int argc, char *argv[])
{
	argc = 0;
	printf(" %d a la %d es %d", atoi(argv[1]),
	 atoi(argv[2]),
	  ft_iterative_power(atoi(argv[1]), atoi(argv[2])));
}*/
