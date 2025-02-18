/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 03:55:11 by kseligma          #+#    #+#             */
/*   Updated: 2024/09/06 23:10:58 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H

# define FT_BTREE_H

# include <stdlib.h>
 
typedef struct s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}	t_btree;

/* Creates a node with `item` */
t_btree	*btree_create_node(void *item);

/* Applies `applyf` using pre-order traversal */
void	btree_apply_prefix(t_btree *root, void (*applyf)(void *));

/* Applies `applyf` using in-order traversal */
void	btree_apply_infix(t_btree *root, void (*applyf)(void *));

/* Applies `applyf` using pos-order traversal */
void	btree_apply_suffix(t_btree *root, void (*applyf)(void *));

/* On an ordered tree, inserts a new node with `data` */
void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *));

/* Searchs in the the first node where using `cmpf` with `data_ref` and the node's data returns 0 */
void	*btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *));

/* Returns the length of one of the longest branchs of the tree */
int		btree_level_count(t_btree *root);

/* Applies `applyf` to all node's data, where current_level is node's deepth and `is_first_elem` a boolean meaning 
if this node if the first found on this level */
void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem));

#endif
