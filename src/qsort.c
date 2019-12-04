/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:09:31 by thallot           #+#    #+#             */
/*   Updated: 2019/06/28 10:52:27 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		get_median(t_lst *a)
{
	int *tab;

	tab = make_tab(a);
	quicksort(tab, 0, list_size(a) - 1);
	if (list_size(a) % 2 == 0)
		return (tab[(list_size(a) + 1) / 2]);
	else
		return (tab[list_size(a) / 2]);
}

int		*make_tab(t_lst *a)
{
	t_elem	*elem;
	int		*tab;
	int		size;
	int		i;

	i = 0;
	elem = a->first;
	size = list_size(a);
	tab = (int *)ft_memalloc(sizeof(int) * size);
	while (i < size)
	{
		tab[i] = elem->nb;
		elem = elem->next;
		i++;
	}
	return (tab);
}

int		partition(int arr[], int low, int high)
{
	int pivot;
	int i;
	int j;

	i = (low - 1);
	pivot = arr[high];
	j = low;
	while (j <= high - 1)
	{
		if (arr[j] <= pivot)
		{
			i++;
			ft_swap(&arr[i], &arr[j]);
		}
		j++;
	}
	ft_swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void	quicksort(int arr[], int low, int high)
{
	int pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		quicksort(arr, low, pi - 1);
		quicksort(arr, pi + 1, high);
	}
}
