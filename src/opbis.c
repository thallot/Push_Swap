/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opbis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 14:13:00 by thallot           #+#    #+#             */
/*   Updated: 2019/06/27 14:16:17 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	op_rx(t_lst *lst)
{
	int	nb;

	if (!lst->first)
		return ;
	nb = ft_destroy_first(lst);
	ft_pushback(lst, nb);
}

void	op_rr(t_lst *lst_a, t_lst *lst_b)
{
	if (lst_a)
		op_rx(lst_a);
	if (lst_b)
		op_rx(lst_b);
}

void	op_rrx(t_lst *lst)
{
	int nb;

	if (!lst)
		return ;
	if (list_size(lst) > 1)
	{
		nb = ft_destroy_last(lst);
		ft_pushfront(lst, nb);
	}
}

void	op_rrr(t_lst *lst_a, t_lst *lst_b)
{
	if (lst_a)
		op_rrx(lst_a);
	if (lst_b)
		op_rrx(lst_b);
}

int		part_list_b(t_lst **list_a, t_lst **list_b, char **str, int end)
{
	t_elem	*elem;
	int		i;

	i = 0;
	if (end < 3)
		return (0);
	elem = (*list_b)->first;
	(*list_b)->pivot = get_med(*list_b, end);
	while (i < end)
	{
		if (elem->nb > (*list_b)->pivot)
		{
			pa_inst(str);
			op_pa(*list_a, *list_b);
			elem = (*list_b)->first;
		}
		else if (end - i > 1)
		{
			rb_inst(str);
			op_rx(*list_b);
			elem = (*list_b)->first;
		}
		i++;
	}
	return (list_size(*list_b) / 2);
}
