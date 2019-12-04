/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 09:34:34 by thallot           #+#    #+#             */
/*   Updated: 2019/06/27 14:35:04 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_elem	*sa_op(t_lst *list_a, t_elem *elem_a, char **str)
{
	char *tmp;

	if (elem_a->next->nb < elem_a->nb)
	{
		tmp = *str;
		*str = ft_strjoin(*str, "sa\n");
		ft_memdel((void **)&tmp);
		op_sx(list_a);
		elem_a = list_a->first;
	}
	return (elem_a);
}

void	rotate_opti(int iteropti, int size, t_lst *list_a, char **str)
{
	char *tmp;

	if (iteropti <= size / 2)
	{
		while (iteropti--)
		{
			tmp = *str;
			*str = ft_strjoin(*str, "ra\n");
			ft_memdel((void **)&tmp);
			op_rx(list_a);
		}
	}
	else
	{
		while (iteropti++ < size)
		{
			tmp = *str;
			*str = ft_strjoin(*str, "rra\n");
			ft_memdel((void **)&tmp);
			op_rrx(list_a);
		}
	}
}

int		get_iter(int min, t_elem *elem_a, t_lst *list_a)
{
	int iter;
	int iteropti;

	iter = 0;
	iteropti = 0;
	while (elem_a)
	{
		if (min > elem_a->nb)
		{
			min = elem_a->nb;
			iteropti = iter;
		}
		iter++;
		elem_a = elem_a->next;
	}
	elem_a = list_a->first;
	return (iteropti);
}

t_lst	*pb_secure(t_lst *list_b, t_lst *list_a, char **str)
{
	int		nb;
	char	*tmp;

	if (!list_b)
	{
		tmp = *str;
		*str = ft_strjoin(*str, "pb\n");
		ft_memdel((void **)&tmp);
		nb = ft_destroy_first(list_a);
		list_b = init(nb);
	}
	else
	{
		op_pb(list_a, list_b);
		tmp = *str;
		*str = ft_strjoin(*str, "pb\n");
		ft_memdel((void **)&tmp);
	}
	return (list_b);
}

int		is_ok(t_lst *list_a, t_lst *list_b)
{
	if (is_sort(list_a))
	{
		if (list_b)
		{
			if (!list_b->first)
				return (1);
			return (0);
		}
		return (1);
	}
	return (0);
}
