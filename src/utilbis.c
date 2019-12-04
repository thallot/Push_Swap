/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilbis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 14:17:47 by thallot           #+#    #+#             */
/*   Updated: 2019/07/17 14:02:32 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		error_int(t_lst *list, t_lst *list_b)
{
	if (list)
	{
		if (list->first)
			ft_lstdelete(&(list)->first);
		ft_memdel((void **)&list);
	}
	if (list_b)
	{
		if (list_b->first)
			ft_lstdelete(&(list_b)->first);
		ft_memdel((void **)&list_b);
	}
	ft_putendl("Error");
	return (0);
}

int		error_str(t_lst *list, t_lst *list_b, char *str)
{
	ft_memdel((void **)&str);
	if (list)
	{
		ft_lstdelete(&(list)->first);
		ft_memdel((void**)&list);
	}
	if (list_b)
	{
		if (list_b->first)
			ft_lstdelete(&(list_b)->first);
		ft_memdel((void**)&list_b);
	}
	ft_putendl("Error");
	return (0);
}

int		error_strbis(char *str)
{
	ft_memdel((void **)&str);
	return (0);
}

void	ra_instruction(char **str)
{
	char *tmp;

	tmp = *str;
	*str = ft_strjoin(*str, "ra\n");
	ft_memdel((void **)&tmp);
}

t_lst	*init_error(t_lst *list, char **tab)
{
	free_tab(tab);
	list = init(0);
	list->error = 1;
	return (list);
}
