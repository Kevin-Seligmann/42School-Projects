/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:26:28 by kseligma          #+#    #+#             */
/*   Updated: 2023/10/30 19:26:30 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write_str(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_sort(int argc, char **argv);

int	main(int argc, char *argv[])
{
	int	ind;

	ft_sort(argc, argv);
	ind = 1;
	while (ind < argc)
	{
		ft_write_str(argv[ind]);
		ind ++;
	}
	return (0);
}

void	ft_write_str(char *str)
{
	int	ind;

	ind = 0;
	while (str[ind] != 0)
	{
		write(1, &str[ind], 1);
		ind ++;
	}
	write(1, "\n", 1);
}

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

void	ft_sort(int argc, char **argv)
{
	int		ind;
	int		ind2;
	char	*aux;

	ind = 1;
	while (ind < argc)
	{
		ind2 = 1;
		while (ind2 < argc - 1)
		{
			if (ft_strcmp(argv[ind2], argv[ind2 + 1]) > 0)
			{
				aux = argv[ind2];
				argv[ind2] = argv[ind2 + 1];
				argv[ind2 + 1] = aux;
			}
			ind2 ++;
		}
		ind ++;
	}
}
