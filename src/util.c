/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:20:08 by thallot           #+#    #+#             */
/*   Updated: 2019/06/28 10:46:45 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int			valid_input(char *str)
{
	int			i;
	long int	nb;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			return (0);
		i++;
	}
	nb = ft_atoli(str);
	if (nb > INT_MAX || nb < INT_MIN)
		return (0);
	return (1);
}

long int	ft_atoli(const char *str)
{
	unsigned int		i;
	long int			nb;
	int					sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] == '\f' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}

int			is_present(t_elem *lst, int nb)
{
	if (!lst)
		return (1);
	while (lst)
	{
		if (lst->nb == nb)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void		ft_free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_memdel((void **)&tab[i]);
		i++;
	}
	ft_memdel((void **)&tab);
}

t_lst		*parser_argv(t_lst *list, char *str)
{
	char	**tab;
	int		i;

	i = 1;
	while (*str == ' ')
		str = str + 1;
	tab = ft_strsplit(str, ' ');
	if (tab && tab[0] && valid_input(tab[0]))
		list = init(ft_atoi(tab[0]));
	else
		return (init_error(list, tab));
	while (tab[i])
	{
		if (is_present(list->first, ft_atoi(tab[i])) && valid_input(tab[i]))
			ft_pushback(list, ft_atoi(tab[i]));
		else
		{
			free_tab(tab);
			list->error = 1;
			return (list);
		}
		i++;
	}
	ft_free_tab(tab);
	return (list);
}
