/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 14:26:35 by thallot           #+#    #+#             */
/*   Updated: 2019/07/15 11:04:56 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_memdel((void **)&tab[i]);
		i++;
	}
	ft_memdel((void **)&tab);
	return (0);
}

int		free_exit(char *str, t_lst *list_a, t_lst *list_b)
{
	ft_memdel((void **)&str);
	ft_lstdelete(&(list_a)->first);
	ft_memdel((void **)&list_a);
	ft_memdel((void **)&list_b);
	return (0);
}

void	free_exit_check(t_lst *list_a, t_lst *list_b)
{
	if (list_a)
	{
		if (list_a->first)
			ft_lstdelete(&(list_a)->first);
		ft_memdel((void **)&list_a);
	}
	ft_memdel((void **)&list_a);
	if (list_b)
	{
		if (list_b->first)
			ft_lstdelete(&(list_b)->first);
		ft_memdel((void **)&list_b);
	}
}
