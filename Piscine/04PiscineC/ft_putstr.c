/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:05:19 by kseligma          #+#    #+#             */
/*   Updated: 2023/10/26 15:05:21 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstre(char *str);

void	ft_putstr(char *str)
{
	unsigned int	ind;

	ind = 0;
	while (str[ind] != 0)
	{
		write(1, &str[ind], 1);
		ind++;
	}
}
