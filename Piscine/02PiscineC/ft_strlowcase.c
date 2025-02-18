/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowercase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:30:49 by kseligma          #+#    #+#             */
/*   Updated: 2023/10/23 19:30:54 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char	*ptr_str;

	ptr_str = str;
	while (*str != '\0')
	{
		if (*str > 64 && *str < 91)
		{
			*str += 32;
		}
		str ++;
	}
	return (ptr_str);
}
