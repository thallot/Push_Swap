/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:32:31 by thallot           #+#    #+#             */
/*   Updated: 2019/06/21 16:01:56 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_lst	*init(int nb)
{
	t_lst	*lst;
	t_elem	*element;

	if (!(lst = (t_lst *)ft_memalloc(sizeof(*lst))))
		return (NULL);
	if (!(element = (t_elem *)ft_memalloc(sizeof(*element))))
	{
		ft_memdel((void**)&lst);
		return (NULL);
	}
	element->nb = nb;
	element->next = NULL;
	lst->first = element;
	return (lst);
}

void	print_lst(t_lst *lst)
{
	t_elem *elem;

	if (lst == NULL)
	{
		ft_putendl("Liste vide");
		return ;
	}
	elem = lst->first;
	while (elem != NULL)
	{
		ft_putnbr(elem->nb);
		ft_putstr(" -> ");
		elem = elem->next;
	}
	ft_putendl("NULL");
}

void	ft_pushback(t_lst *lst, int nb)
{
	t_elem *new;
	t_elem *current;

	current = lst->first;
	if (!(new = ft_memalloc(sizeof(*new))))
		return ;
	if (lst == NULL || new == NULL)
		return ;
	new->nb = nb;
	new->next = NULL;
	if (lst->first != NULL)
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
	else
		lst->first = new;
}

void	ft_pushfront(t_lst *lst, int nb)
{
	t_elem *new;
	t_elem *current;

	current = lst->first;
	if (!(new = ft_memalloc(sizeof(*new))))
		return ;
	new->nb = nb;
	new->next = current;
	lst->first = new;
}
