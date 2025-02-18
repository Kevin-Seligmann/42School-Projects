/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:47:54 by kseligma          #+#    #+#             */
/*   Updated: 2023/11/09 15:48:07 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2);

void	ft_sort_string_tab(char **tab)
{
	int		ind;
	int		ind2;
	char	*aux;

	ind = 0;
	ind2 = 0;
	if (tab[ind] == 0)
		return ;
	while (tab[ind] != 0)
	{
		ind2 = 0;
		while (tab[ind2] != 0)
		{
			if (ft_strcmp(tab[ind], tab[ind2]) < 0)
			{
				aux = tab[ind];
				tab[ind] = tab[ind2];
				tab[ind2] = aux;
			}
			ind2 ++;
		}
		ind ++;
	}
}

/*
int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != 0 || *s2 != 0)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1 ++;
		s2 ++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	ind;

	ind = 1;
	ft_sort_string_tab(&argv[1]);
	while(argv[ind] != 0)
	{
		printf("Str %s \n", argv[ind]);
		ind ++;
	}
}
*/
