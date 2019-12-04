/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 10:39:39 by thallot           #+#    #+#             */
/*   Updated: 2019/07/15 10:55:55 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		main(int argc, char **argv)
{
	t_lst	*list_a;
	t_lst	*list_b;
	char	*str;

	list_a = NULL;
	list_b = NULL;
	str = ft_strnew(0);
	list_a = init_lst(argv, argc, list_a, 0);
	if (!list_a)
		return (error_strbis(str));
	if (list_a->error)
		return (error_str(list_a, list_b, str));
	if (!is_sort(list_a))
	{
		if (list_size(list_a) > 20)
			mix_sort(&list_a, &list_b, list_size(list_a), &str);
		else
			str = sort_list(list_a, list_b, str);
		str = opti_instruction(str);
	}
	ft_putstr(str);
	return (free_exit(str, list_a, list_b));
}
