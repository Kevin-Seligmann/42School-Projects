/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:27:18 by kseligma          #+#    #+#             */
/*   Updated: 2023/10/23 18:29:51 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	char	*ptr_dest;

	ptr_dest = dest;
	while (*src != '\0')
	{
		*dest = *src;
		src ++;
		dest ++;
	}
	*dest = *src;
	return (ptr_dest);
}
