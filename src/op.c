/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 11:02:47 by thallot           #+#    #+#             */
/*   Updated: 2019/06/27 14:15:58 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	op_sx(t_lst *lst)
{
	t_elem	*elem_a;
	t_elem	*elem_b;

	if (!lst->first || !lst->first->next)
		return ;
	elem_a = lst->first;
	elem_b = lst->first->next;
	elem_a->next = elem_b->next;
	elem_b->next = elem_a;
	lst->first = elem_b;
}

void	op_ss(t_lst *lst_a, t_lst *lst_b)
{
	op_sx(lst_a);
	op_sx(lst_b);
}

void	op_pa(t_lst *lst_a, t_lst *lst_b)
{
	int	nb;

	if (!lst_b)
		return ;
	nb = ft_destroy_first(lst_b);
	ft_pushfront(lst_a, nb);
}

void	op_pb(t_lst *lst_a, t_lst *lst_b)
{
	int	nb;

	if (!lst_a->first)
		return ;
	nb = ft_destroy_first(lst_a);
	ft_pushfront(lst_b, nb);
}
