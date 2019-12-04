/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 10:40:48 by thallot           #+#    #+#             */
/*   Updated: 2019/07/17 13:55:08 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_lst	*error(t_lst *list, int code)
{
	ft_lstdelete(&(list)->first);
	ft_memdel((void**)&list);
	ft_putendl("error");
	(void)code;
	return (NULL);
}

t_lst	*init_lst(char **argv, int argc, t_lst *list, int i)
{
	if (argc == 2)
	{
		list = parser_argv(list, argv[1]);
		return (list);
	}
	while (++i < argc)
	{
		if (valid_input(argv[i]) != 0)
		{
			if (i == 1)
				list = init(ft_atoi(argv[i]));
			else if (is_present(list->first, ft_atoi(argv[i])))
				ft_pushback(list, ft_atoi(argv[i]));
			else
				list->error = 1;
		}
		else
		{
			if (!list)
				list = init(ft_atoi(argv[i]));
			list->error = 1;
		}
	}
	return (list);
}

t_lst	*do_operation(char *str, t_lst *list_a, t_lst *list_b)
{
	if (!ft_strcmp(str, "rra"))
		op_rrx(list_a);
	if (!ft_strcmp(str, "rrb"))
		op_rrx(list_b);
	if (!ft_strcmp(str, "rrr"))
		op_rrr(list_a, list_b);
	if (!ft_strcmp(str, "ra"))
		op_rx(list_a);
	if (!ft_strcmp(str, "rb") && list_b)
		op_rx(list_b);
	if (!ft_strcmp(str, "rr"))
		op_rr(list_a, list_b);
	if (!ft_strcmp(str, "pa"))
		op_pa(list_a, list_b);
	if (!ft_strcmp(str, "pb"))
		list_b = op_pb_secure(list_a, list_b);
	if (!ft_strcmp(str, "sa"))
		op_sx(list_a);
	if (!ft_strcmp(str, "sb") && list_b)
		op_sx(list_b);
	if (!ft_strcmp(str, "ss") && list_b)
		op_ss(list_a, list_b);
	return (list_b);
}

int		cmp_instruction(char *str)
{
	if (!ft_strcmp(str, "rra") || !ft_strcmp(str, "rrb")
			|| !ft_strcmp(str, "rrr") || !ft_strcmp(str, "rr")
			|| !ft_strcmp(str, "sa") || !ft_strcmp(str, "sb")
			|| !ft_strcmp(str, "ss") || !ft_strcmp(str, "pa")
			|| !ft_strcmp(str, "pb") || !ft_strcmp(str, "ra")
			|| !ft_strcmp(str, "rb"))
		return (1);
	return (0);
}

t_lst	*read_instruction(t_lst *list_a, t_lst *list_b)
{
	char	*str;
	int		fd;

	fd = 0;
	str = NULL;
	while (get_next_line(fd, &str) == 1)
	{
		if (!cmp_instruction(str))
		{
			ft_memdel((void **)&str);
			list_a->error = 1;
			fd = -1;
		}
		else
			list_b = do_operation(str, list_a, list_b);
		ft_memdel((void **)&str);
	}
	ft_memdel((void **)&str);
	return (list_b);
}
