/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:48:16 by kseligma          #+#    #+#             */
/*   Updated: 2023/10/29 18:48:35 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 1 || nb == 0)
		return (1);
	return (nb * (ft_recursive_factorial(nb - 1)));
}

/*int	main(int argc, char *argv[])
{
	argc = 0;
	printf("Fact de %d es %d",
	 atoi(argv[1]), ft_recursive_factorial(atoi(argv[1])));
}*/
