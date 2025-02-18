/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:43:00 by kseligma          #+#    #+#             */
/*   Updated: 2024/01/14 17:24:31 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	total_space(char const *s, char c)
{
	size_t	len;
	char	*str;
	char	*ref;

	if (s == 0)
		return (0);
	ref = 0;
	len = 1;
	str = (char *) s;
	while (*str != 0)
	{
		if (*str != c && ref == 0)
			ref = str;
		if ((*str == c || *(str + 1) == 0) && ref != 0)
		{
			len ++;
			ref = 0;
		}
		str ++;
	}
	return (len);
}

static char	**freeall(char ***strs, size_t ind)
{
	size_t	indf;

	indf = 0;
	while (indf <= ind)
	{
		free((*strs)[indf]);
		indf ++;
	}
	free(*strs);
	return (0);
}

static char	**setend(char **strs, size_t ind)
{
	(strs)[ind] = 0;
	return (strs);
}

static size_t	bcalc(char *str, char *ref, char c)
{
	if (*str == c)
		return (str - ref);
	return (str - ref + 1);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	char	*str;
	char	*ref;
	size_t	ind;

	strs = (char **) malloc(total_space(s, c) * sizeof(char *));
	if (strs == 0 || s == 0)
		return (0);
	str = (char *) s;
	ref = 0;
	ind = 0;
	while (*str != 0)
	{
		if (*str != c && ref == 0)
			ref = str;
		if ((*str == c || *(str + 1) == 0) && ref != 0)
		{
			strs[ind] = ft_substr((char const *) ref, 0, bcalc(str, ref, c));
			if (strs[ind++] == 0)
				return (freeall(&strs, ind - 1));
			ref = 0;
		}
		str ++;
	}
	return (setend(strs, ind));
}
