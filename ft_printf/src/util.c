/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:55:09 by kseligma          #+#    #+#             */
/*   Updated: 2024/02/17 07:42:44 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(size_t n, char *base)
{
	char	p_c[32 + 1];
	int		base_len;
	int		i;

	if (!base || !(*base))
		return (0);
	base_len = ft_strlen(base);
	i = 32 - 1;
	while (n > 0 || i == 32 - 1)
	{
		p_c[i] = base[n % base_len];
		n /= base_len;
		i --;
	}
	p_c[32] = 0;
	return (ft_strdup(&(p_c[i + 1])));
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++ != 0)
		len ++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	char	l;
	char	*ptr;

	ptr = (char *) s;
	l = (char) c;
	while (*ptr != l && *ptr != 0)
		ptr ++;
	if (*ptr == l)
		return (ptr);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	ind;
	char	*cpy;
	char	*ptr;

	ptr = (char *) s1;
	len = ft_strlen(ptr);
	cpy = (char *) malloc(len + 1);
	if (cpy == 0)
		return (0);
	ind = 0;
	while (ind < len)
	{
		cpy[ind] = ptr[ind];
		ind ++;
	}
	cpy[ind] = 0;
	return (cpy);
}
