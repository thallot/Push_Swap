/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 10:37:15 by thallot           #+#    #+#             */
/*   Updated: 2019/06/21 16:02:03 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		main(int argc, char **argv)
{
	t_lst *list_a;
	t_lst *list_b;

	list_a = NULL;
	list_b = NULL;
	list_a = init_lst(argv, argc, list_a, 0);
	if (!list_a)
		return (0);
	if (list_a->error)
		return (error_int(list_a, list_b));
	list_b = read_instruction(list_a, list_b);
	if (list_a->error)
		return (error_int(list_a, list_b));
	else
	{
		is_ok(list_a, list_b) ? ft_putendl("OK") : ft_putendl("KO");
		free_exit_check(list_a, list_b);
	}
	return (0);
}
