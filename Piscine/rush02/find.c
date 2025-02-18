/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabou-me <zabou-me@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:47:02 by zabou-me          #+#    #+#             */
/*   Updated: 2023/11/04 17:29:00 by zabou-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

unsigned long	ft_strlen(char *str);
char			*select_file(char *f);

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0' && str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0' && str[i - 1] == '\n')
				return (&str[i + j + 1]);
			j++;
		}
		i++;
	}
	return (0);
}

void	find(char *digit, char *dict)
{
	char	*linea;

	linea = ft_strstr(dict, digit);
	if (linea == 0)
	{
		write(1, "Dict error", 10);
		return ;
	}
	while (*linea == ' ')
		linea ++;
	if (*linea == ':')
		linea ++;
	else
	{
		find(digit, linea);
		return ;
	}
	while (*linea == ' ')
		linea ++;
	while (*linea != '\n' && *linea != 0)
	{
		write(1, linea, 1);
		linea ++;
	}
}

/*int	main(int argc, char **argv)
{
	find(argv[1], select_file(argv[2]));
	return (0);
}*/
