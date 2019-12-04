/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 09:37:49 by thallot           #+#    #+#             */
/*   Updated: 2019/06/28 10:44:09 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		get_med(t_lst *a, int end)
{
	int *tab;
	int med;

	tab = get_tab(a, end);
	quicksort(tab, 0, end);
	if (list_size(a) % 2 == 0)
		med = tab[(end + 1) / 2];
	else
		med = tab[(end) / 2];
	ft_memdel((void**)&tab);
	return (med);
}

int		*get_tab(t_lst *a, int end)
{
	t_elem	*elem;
	int		*tab;
	int		i;

	i = 0;
	elem = a->first;
	tab = (int *)ft_memalloc(sizeof(int) * (end + 1));
	while (i < end - 1)
	{
		tab[i] = elem->nb;
		elem = elem->next;
		i++;
	}
	return (tab);
}

int		part_list(t_lst **list_a, t_lst **list_b, char **str, int end)
{
	t_elem	*elem;
	int		i;

	i = 0;
	if (end < 3)
		return (0);
	elem = (*list_a)->first;
	(*list_a)->pivot = get_med(*list_a, end);
	while (i < end)
	{
		if (elem->nb < (*list_a)->pivot)
		{
			*list_b = pb_secure(*list_b, *list_a, str);
			elem = (*list_a)->first;
		}
		else if (end - i > 1)
		{
			ra_instruction(str);
			op_rx(*list_a);
			elem = (*list_a)->first;
		}
		i++;
	}
	return (list_size(*list_a) / 2);
}

void	depop_b(t_lst *a, t_lst *b, int size, char **str)
{
	char *tmp;

	while (size--)
	{
		tmp = *str;
		*str = ft_strjoin(*str, "pa\n");
		ft_strdel(&tmp);
		op_pa(a, b);
	}
}

void	q_sort(t_lst **a, t_lst **b, int end, char **str)
{
	int pi;

	pi = part_list(a, b, str, end);
	end = (end / 2);
	while (end > 1)
	{
		pi = part_list(a, b, str, end);
		end /= 2;
	}
	depop_b(*a, *b, list_size(*b), str);
	*str = sort_list(*a, *b, *str);
}
