/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 22:06:10 by kseligma          #+#    #+#             */
/*   Updated: 2024/09/06 22:10:23 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *))
{
	void	*ret;

	if (!root || !cmpf)
		return (NULL);
	ret = btree_search_item(root->left, data_ref, cmpf);
	if (!ret && cmpf(root->item, data_ref) == 0)	
		ret = root->item;
	if (!ret)
		ret = btree_search_item(root->right, data_ref, cmpf);
	return (ret);
}
