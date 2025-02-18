/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:28:12 by kseligma          #+#    #+#             */
/*   Updated: 2023/10/24 19:29:00 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*dest_og;
	unsigned int	ind;

	ind = 0;
	dest_og = dest;
	while (*dest != '\0')
		dest ++;
	while (*src != '\0' && ind < nb)
	{
		*dest = *src;
		src ++;
		dest ++;
		ind ++;
	}
	*dest = 0;
	return (dest_og);
}
