/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:36:38 by kseligma          #+#    #+#             */
/*   Updated: 2023/10/23 18:40:21 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char			*ptr_dest;
	unsigned int	ind;

	ind = 0;
	ptr_dest = dest;
	while (*src != '\0' && ind < n)
	{
		*dest = *src;
		src ++;
		dest ++;
		ind ++;
	}
	while (ind < n)
	{
		*dest = '\0';
		dest ++;
		ind ++;
	}
	return (ptr_dest);
}
