/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstbis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 14:16:40 by thallot           #+#    #+#             */
/*   Updated: 2019/06/27 14:16:41 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		ft_destroy_first(t_lst *lst)
{
	t_elem	*elem;
	int		nb;

	elem = lst->first;
	if (lst == NULL)
		return (0);
	nb = 0;
	if (lst->first != NULL)
	{
		nb = elem->nb;
		lst->first = elem->next;
		ft_memdel((void **)&elem);
	}
	return (nb);
}

int		ft_destroy_last(t_lst *lst)
{
	t_elem	*elem;
	int		nb;

	elem = lst->first;
	if (lst == NULL || !lst->first)
		return (0);
	nb = 0;
	while (elem->next->next)
		elem = elem->next;
	nb = elem->next->nb;
	ft_memdel((void **)&elem->next);
	elem->next = NULL;
	return (nb);
}

void	ft_lstdelete(t_elem **alst)
{
	if (!alst)
		return ;
	while ((*alst)->next)
		ft_lstdelete(&(*alst)->next);
	ft_lstdeleteone(alst);
}

void	ft_lstdeleteone(t_elem **alst)
{
	if (!alst)
		return ;
	free(*alst);
	(*alst) = NULL;
}
