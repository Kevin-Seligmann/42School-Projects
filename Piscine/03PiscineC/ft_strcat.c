/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:16:46 by kseligma          #+#    #+#             */
/*   Updated: 2023/10/24 19:16:58 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char	*dest_og;

	dest_og = dest;
	while (*dest != 0)
		dest ++;
	while (*src != 0)
	{
		*dest = *src;
		src ++;
		dest ++;
	}
	*dest = 0;
	return (dest_og);
}
