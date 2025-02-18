/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 22:12:50 by kseligma          #+#    #+#             */
/*   Updated: 2024/09/06 22:20:03 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

static void btree_count(t_btree *root, int current_level, int *max_level)
{
	if (!root)
		return ;
	if (current_level > *max_level)
		(*max_level)++;
	btree_count(root->left, current_level + 1, max_level);
	btree_count(root->right, current_level + 1, max_level);
}

int	btree_level_count(t_btree *root)
{
	int	current_level;
	int	max_level;

	current_level = 0;
	max_level = 0;
	btree_count(root, current_level + 1, &max_level);
	return (max_level);
}
