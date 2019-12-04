/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:39:36 by thallot           #+#    #+#             */
/*   Updated: 2019/06/28 10:54:00 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		list_size(t_lst *lst)
{
	int		size;
	t_elem	*elem;

	elem = lst->first;
	size = 0;
	while (elem)
	{
		size++;
		elem = elem->next;
	}
	return (size);
}

char	*sort_list(t_lst *list_a, t_lst *list_b, char *str)
{
	t_elem	*elem_a;
	int		min;
	int		iter;

	elem_a = list_a->first;
	min = elem_a->nb;
	if (list_size(list_a) == 3 && !list_b)
	{
		if (little_sort(&list_a, &str) == 1)
			return (str);
	}
	if (is_sort(list_a) || !list_a->first->next)
	{
		if (list_b)
			return ((str = resort_list(list_a, list_b, str)));
		return (str);
	}
	iter = get_iter(min, elem_a, list_a);
	rotate_opti(iter, list_size(list_a), list_a, &str);
	list_b = pb_secure(list_b, list_a, &str);
	str = sort_list(list_a, list_b, str);
	return (str);
}

char	*resort_list(t_lst *list_a, t_lst *list_b, char *str)
{
	t_elem	*elem_b;
	char	*tmp;
	int		iter;

	iter = 0;
	elem_b = list_b->first;
	iter = list_size(list_b);
	while (iter--)
	{
		tmp = str;
		str = ft_strjoin(str, "pa\n");
		ft_memdel((void **)&tmp);
		op_pa(list_a, list_b);
	}
	ft_memdel((void **)&list_b);
	return (str);
}

int		is_sort(t_lst *list)
{
	t_elem *elem;

	if (!list->first)
		return (0);
	elem = list->first;
	while (elem->next)
	{
		if (elem->nb > elem->next->nb)
			return (0);
		elem = elem->next;
	}
	return (1);
}
