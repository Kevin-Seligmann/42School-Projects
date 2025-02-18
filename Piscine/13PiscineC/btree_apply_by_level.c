/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 22:20:33 by kseligma          #+#    #+#             */
/*   Updated: 2024/09/06 22:30:40 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

static void	rec_apply(t_btree *node, void (*applyf)(void *item, int current_level, int is_first_elem), int current_level, int *level_found)
{
	if (!node)
		return ;
	if (level_found[current_level] == 0)
	{
		applyf(node->item, current_level, 1);
		level_found[current_level] = 1;
	}
	else
		applyf(node->item, current_level, 0);
	rec_apply(node->left, applyf, current_level + 1, level_found);
	rec_apply(node->right, applyf, current_level + 1, level_found);

}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int	ind;
	int	depth;
	int	*level_found;

	depth = btree_level_count(root);
	level_found = malloc(sizeof(*level_found) * depth);
	if (!level_found)
		return ;
	ind = -1;
	while (++ind < depth)
		level_found[ind] = 0;
	rec_apply(root, applyf, 0, level_found);
	free (level_found);
}
