/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:32:31 by kseligma          #+#    #+#             */
/*   Updated: 2023/10/23 19:32:34 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		is_alphanumeric(char letter);
char	uppercase(char letter);
char	lowercase(char letter);
char	*ft_strcapitalize(char	*str);

char	*ft_strcapitalize(char *str)
{
	char	*ptr_str;
	char	prev;

	ptr_str = str;
	if (is_alphanumeric(*str) == 1)
		*str = uppercase(*str);
	prev = *str;
	while (*str != 0)
	{
		str ++;
		if (is_alphanumeric(prev) == 0 && is_alphanumeric(*str) == 1)
			*str = uppercase(*str);
		if (is_alphanumeric(prev) == 1 && is_alphanumeric(*str) == 1)
			*str = lowercase(*str);
		prev = *str;
	}
	return (ptr_str);
}

int	is_alphanumeric(char letter)
{
	if (letter < '0' || letter > 'z' || (letter > '9' && letter < 'A'))
		return (0);
	if (letter > 'Z' && letter < 'a')
		return (0);
	return (1);
}

char	uppercase(char letter)
{
	if (letter >= 'a' && letter <= 'z')
		letter -= 32;
	return (letter);
}

char	lowercase(char letter)
{
	if (letter >= 'A' && letter <= 'Z')
		letter += 32;
	return (letter);
}
