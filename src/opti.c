/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 13:54:32 by thallot           #+#    #+#             */
/*   Updated: 2019/07/31 12:59:16 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_lst	*op_pb_secure(t_lst *list_a, t_lst *list_b)
{
	if (!list_b)
		list_b = init(ft_destroy_first(list_a));
	else
		op_pb(list_a, list_b);
	return (list_b);
}

char	*opti_instruction(char *str)
{
	char	**tab;
	int		i;
	char	*instruction;
	char	*tmp;

	tab = ft_split(str, '\n', 1);
	i = 0;
	instruction = ft_strnew(0);
	while (tab[i])
	{
		if (!ft_strcmp(tab[i], "pb\n") && !ft_strcmp(tab[i + 1], "pa\n"))
			i = i + 2;
		else
		{
			tmp = instruction;
			instruction = ft_strjoin(instruction, tab[i]);
			ft_memdel((void **)&tmp);
			i++;
		}
	}
	free_tab(tab);
	ft_memdel((void **)&str);
	return (instruction);
}

int		little_sort(t_lst **a, char **str)
{
	t_elem	*elem;
	char	*tmp;

	elem = (*a)->first;
	if (elem->nb > elem->next->nb && elem->next->nb > elem->next->next->nb)
	{
		tmp = *str;
		*str = ft_strjoin(*str, "sa\nrra\n");
		ft_strdel(&tmp);
		return (1);
	}
	else if (elem->nb > elem->next->nb && elem->next->nb < elem->next->next->nb
						&& elem->nb < elem->next->next->nb)
	{
		tmp = *str;
		*str = ft_strjoin(*str, "sa\n");
		ft_strdel(&tmp);
		return (1);
	}
	return (0);
}

void	pa_inst(char **str)
{
	char *tmp;

	tmp = *str;
	*str = ft_strjoin(*str, "pa\n");
	ft_strdel(&tmp);
}

void	rb_inst(char **str)
{
	char *tmp;

	tmp = *str;
	*str = ft_strjoin(*str, "rb\n");
	ft_strdel(&tmp);
}
