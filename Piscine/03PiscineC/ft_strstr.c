/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:46:24 by kseligma          #+#    #+#             */
/*   Updated: 2023/10/24 20:06:46 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char	*str, char *to_find)
{
	int	ind1;
	int	ind2;

	ind1 = 0;
	ind2 = 0;
	if (to_find[0] == 0)
		return (str);
	while (str[ind1] != 0)
	{
		ind2 = 0;
		while (str[ind1 + ind2] == to_find[ind2])
		{
			if (to_find[ind2 + 1] == 0)
				return (&str[ind1]);
			ind2++;
		}
		ind1 ++;
	}
	return (0);
}
