/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:53:40 by kseligma          #+#    #+#             */
/*   Updated: 2024/09/06 23:06:03 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

/* Creates a t_list */
t_list	*ft_create_elem(void *data);

/* Creates node in front of list */
void	ft_list_push_front(t_list **begin_list, void *data);

/* List size */
int		ft_list_size(t_list *begin_list);

/* Returns last node */
t_list	*ft_list_last(t_list *begin_list);

/* Creates node at the tail of list */
void	ft_list_push_back(t_list **begin_list, void *data);

/* From a char **, creates a list with all its strings */
t_list	*ft_list_push_strs(int size, char **strs);

/* Passes `free_fct` function to all the data, and frees each node */
void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *));

/* Returns the node on the `nbr`'th position*/
t_list	*ft_list_at(t_list *begin_list, unsigned int nbr);

/* Reverses the list */
void	ft_list_reverse(t_list **begin_list);

/* Applies `f` to all data */
void	ft_list_foreach(t_list *begin_list, void (*f)(void *));

/* Applies `f` to all data if using `cmp` with `data_ref` and the node's data returns 0 */
void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)());

/* Returns the first node where using `cmp` with `data_ref` and node's data returns 0 */
t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());

/* Removes all nodes where using `cmp` with `data_ref` and the node's data returns 0, passing `free_fct` to destroy the data of the deleted node */
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));

/* Sorts a list */
void	ft_list_sort(t_list **begin_list, int (*cmp)());

/* Reverses a list (From a t_list *, instead of a t_list **) */
void	ft_list_reverse_fun(t_list *begin_list);

/* Inserts a a noed with `data` on a sorted list, using `cmp` */
void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)());

/* Merges the sorted list list2 into list1, list1 remains sorted */
void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)());

#endif
