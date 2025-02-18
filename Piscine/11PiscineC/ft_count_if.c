/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:36:07 by kseligma          #+#    #+#             */
/*   Updated: 2023/11/09 13:36:08 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	count;
	int	ind;

	ind = 0;
	count = 0;
	while (tab[ind] != 0)
	{
		if (f(tab[ind]) != 0)
			count ++;
		ind ++;
	}
	return (count);
}
