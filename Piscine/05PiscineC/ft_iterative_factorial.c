/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:36:27 by kseligma          #+#    #+#             */
/*   Updated: 2023/10/29 18:36:28 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>

int	ft_iterative_factorial(int nb)
{
	int	fact;

	if (nb < 0)
		return (0);
	fact = 1;
	while (nb > 1)
	{
		fact *= nb;
		nb --;
	}
	return (fact);
}

/*int	main(int argc, char *argv[])
{
	argc = 0;
	printf("Fact de %d es %d", atoi(argv[1]),
	 ft_iterative_factorial(atoi(argv[1])));
}
*/
