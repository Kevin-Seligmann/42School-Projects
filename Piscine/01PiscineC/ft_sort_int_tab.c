/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:00:05 by kseligma          #+#    #+#             */
/*   Updated: 2023/10/23 16:21:20 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_sort(int size, int *tab);
void	swap(int size, int *tab);

void	ft_sort_int_tab(int *tab, int size)
{
	while (check_sort(size, tab) == 0)
	{
		swap(size, tab);
	}
}

int	check_sort(int size, int *tab)
{
	int	ind;
	int	var;

	ind = 1;
	while (ind < size)
	{
		var = *tab;
		tab ++;
		if (var > *tab)
		{
			return (0);
		}
		ind ++;
	}
	return (1);
}

void	swap(int size, int *tab)
{
	int	ind;
	int	var;
	int	*ptr_before_tab;

	ind = 1;
	while (ind < size)
	{
		ptr_before_tab = tab;
		tab ++;
		if (*ptr_before_tab > *tab)
		{
			var = *tab;
			*tab = *ptr_before_tab;
			*ptr_before_tab = var;
		}
		ind ++;
	}
}
