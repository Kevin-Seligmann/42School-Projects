/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:23:10 by kseligma          #+#    #+#             */
/*   Updated: 2023/10/23 15:42:45 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	carry_first_to_end(int *tab, int size);

void	ft_rev_int_tab(int *tab, int size)
{
	while (size > 0)
	{
		carry_first_to_end(tab, size);
		size --;
	}
}

void	carry_first_to_end(int *tab, int size)
{
	int	var;
	int	*ptr_before_tab;

	while (size > 1)
	{
		ptr_before_tab = tab;
		tab ++;
		var = *tab;
		*tab = *ptr_before_tab;
		*ptr_before_tab = var;
		size --;
	}
}
