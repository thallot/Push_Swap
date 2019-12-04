/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 10:53:50 by thallot           #+#    #+#             */
/*   Updated: 2019/07/15 11:04:36 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_b(int iteropti, int size, t_lst *list_b, char **str)
{
	char *tmp;

	if (iteropti <= size / 2)
	{
		while (iteropti--)
		{
			tmp = *str;
			*str = ft_strjoin(*str, "rb\n");
			ft_memdel((void **)&tmp);
			op_rx(list_b);
		}
	}
	else
	{
		while (iteropti++ < size)
		{
			tmp = *str;
			*str = ft_strjoin(*str, "rrb\n");
			ft_memdel((void **)&tmp);
			op_rrx(list_b);
		}
	}
}

int		get_max(int max, t_elem *elem_b, t_lst **list_b)
{
	int iter;
	int iteropti;

	iter = 0;
	iteropti = 0;
	while (elem_b)
	{
		if (max < elem_b->nb)
		{
			max = elem_b->nb;
			iteropti = iter;
		}
		iter++;
		elem_b = elem_b->next;
	}
	elem_b = (*list_b)->first;
	return (iteropti);
}

void	sort_pivot(t_lst **a, t_lst **b, char **str)
{
	t_elem		*e_b;
	int			iter;
	char		*tmp;

	if (!(*b)->first)
		return ;
	e_b = (*b)->first;
	iter = get_max(e_b->nb, e_b, b);
	rotate_b(iter, list_size(*b), *b, str);
	tmp = *str;
	*str = ft_strjoin(*str, "pa\n");
	ft_strdel(&tmp);
	op_pa(*a, *b);
	sort_pivot(a, b, str);
}

int		get_min_pivot(t_elem *elem_a, t_lst **list_a)
{
	int iter;
	int iteropti;

	iter = 0;
	iteropti = 0;
	while (elem_a)
	{
		if (elem_a->nb <= (*list_a)->pivot)
			iteropti = iter;
		iter++;
		elem_a = elem_a->next;
	}
	elem_a = (*list_a)->first;
	return (iteropti);
}

void	mix_sort(t_lst **a, t_lst **b, int end, char **str)
{
	int iter;

	(void)end;
	if (list_size(*a) < 400)
	{
		while (!is_sort(*a) && list_size(*a) > 8)
			part_list(a, b, str, list_size(*a));
	}
	else
	{
		while (!is_sort(*a) && list_size(*a) > 250)
			part_list(a, b, str, list_size(*a));
		while (list_size(*b) > 120)
			part_list_b(a, b, str, list_size(*b));
		while (!is_sort(*a) && list_size(*a) > 10)
			part_list(a, b, str, list_size(*a));
	}
	while (list_size(*a) > 1 && !is_sort(*a))
	{
		iter = get_iter((*a)->first->nb, (*a)->first, *a);
		rotate_opti(iter, list_size(*a), *a, str);
		*b = pb_secure(*b, *a, str);
	}
	sort_pivot(a, b, str);
}
