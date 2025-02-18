/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:47:09 by kseligma          #+#    #+#             */
/*   Updated: 2023/11/02 18:47:10 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		c_st(char c, char *charset);
int		count_gaps(char *str, char *charset);
char	*ft_strdup(char *src, char *charset);

char	**ft_split(char *str, char	*charset)
{
	char	**ans;
	int		ind;

	ind = 0;
	ans = (char **)malloc((count_gaps(str, charset) + 1) * sizeof(char *));
	if (ans == 0)
		return (0);
	while (*str != 0)
	{
		while (c_st(*str, charset) && *str != 0)
			str ++;
		if (*str != 0)
		{
			ans[ind] = ft_strdup(str, charset);
			if (ans[ind] == 0)
				return (0);
			ind ++;
			while (!c_st(*str, charset) && *str != 0)
				str ++;
		}
	}
	ans[ind] = 0;
	return (ans);
}

char	*ft_strdup(char *src, char *charset)
{
	unsigned int	ind;
	char			*strcpy;

	ind = 0;
	while (src[ind] != 0)
		ind ++;
	strcpy = (char *) malloc(ind + 1);
	if (strcpy == 0)
		return (0);
	ind = 0;
	while (src[ind] != 0 && !c_st(src[ind], charset))
	{
		strcpy[ind] = src[ind];
		ind ++;
	}
	strcpy[ind] = 0;
	return (strcpy);
}

int	c_st(char c, char *charset)
{
	while (*charset != 0)
	{
		if (c == *charset)
			return (1);
		charset ++;
	}
	return (0);
}

int	count_gaps(char *str, char *charset)
{
	int	count;

	count = 0;
	while (c_st(*str, charset))
		str ++;
	if (*str != 0)
		count ++;
	while (*str != 0)
	{
		if (c_st(*str, charset) && !c_st(*(str + 1), charset))
			if (*(str + 1) != 0)
				count ++;
		str ++;
	}
	return (count);
}

/*int	main(int argc, char *argv[])
{
	char	**strs;

	argc = 0;
	strs = ft_split(argv[2], argv[3]);
	if (strs == 0)
	{
		printf("Error");
		return (0);
	}
	while (argc < atoi(argv[1]))
	{
		printf("Ind %d, Str %s\n", argc, strs[argc]);
		free(strs[argc]);
		argc ++;
	}
	printf("Gaps %d\n", count_gaps(argv[2], argv[3]));
	free (strs);
	return (0);
}*/
