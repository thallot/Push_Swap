/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 10:41:33 by thallot           #+#    #+#             */
/*   Updated: 2019/07/18 14:36:48 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

typedef struct	s_elem
{
	int				nb;
	struct s_elem	*next;
}				t_elem;

typedef struct	s_lst
{
	t_elem	*first;
	int		error;
	int		pivot;
	int		max;
}				t_lst;

/*
******************************** lst.c *****************************************
*/
t_lst			*init(int nb);
void			print_lst(t_lst *lst);
void			ft_pushback(t_lst *lst, int nb);
int				ft_destroy_first(t_lst *lst);
int				ft_destroy_last(t_lst *lst);
void			ft_lstdelete(t_elem **alst);
void			ft_lstdeleteone(t_elem **alst);
/*
******************************** util.c ****************************************
*/
int				valid_input(char *str);
long int		ft_atoli(const char *str);
int				is_present(t_elem *lst, int nb);
t_lst			*parser_argv(t_lst *list, char *str);
void			ft_free_tab(char **tab);
void			ft_pushfront(t_lst *lst, int nb);
/*
******************************** checker.c *************************************
*/
t_lst			*init_lst(char **argv, int argc, t_lst *list, int i);
int				cmp_instruction(char *str);
t_lst			*error(t_lst *list, int code);
t_lst			*read_instruction(t_lst *list_a, t_lst *list_b);
t_lst			*do_operation(char *str, t_lst *list_a, t_lst *list_b);
int				list_size(t_lst *lst);
/*
******************************** operation *************************************
*/
void			op_sx(t_lst *lst_a);
void			op_ss(t_lst *lst_a, t_lst *lst_b);
void			op_pa(t_lst *lst_a, t_lst *lst_b);
void			op_pb(t_lst *lst_a, t_lst *lst_b);
void			op_rx(t_lst *lst);
void			op_rr(t_lst *lst_a, t_lst *lst_b);
void			op_rrx(t_lst *lst);
void			op_rrr(t_lst *lst_a, t_lst *lst_b);
/*
******************************** sort.c ****************************************
*/
int				is_sort(t_lst *list);
int				is_desort(t_lst *list_a);
char			*sort_list(t_lst *list_a, t_lst *list_b, char *str);
char			*resort_list(t_lst *list_a, t_lst *list_b, char *str);
/*
******************************** utils_sort.c **********************************
*/
t_elem			*sa_op(t_lst *list_a, t_elem *elem_a, char **str);
void			rotate_opti(int iter, int size, t_lst *list_a, char **str);
int				get_iter(int min, t_elem *elem_a, t_lst *list_a);
t_lst			*pb_secure(t_lst *list_b, t_lst *list_a, char **str);
int				is_ok(t_lst *list_a, t_lst *list_b);
/*
******************************** Autres ****************************************
*/
void			free_tab_int(int **tab, int size);
int				free_tab(char **tab);
char			**ft_split(char const *s, char c, int d);
int				error_int(t_lst *list, t_lst *list_b);
int				error_str(t_lst *list, t_lst *list_b, char *str);
int				error_strbis(char *str);
void			ra_instruction(char **str);
t_lst			*init_error(t_lst *list, char **tab);
char			*opti_instruction(char *str);
void			quicksort(int arr[], int low, int high);
int				partition (int arr[], int low, int high);
int				*make_tab(t_lst *a);
int				get_median(t_lst *a);
void			quicksortl(t_lst **list_a, t_lst **list_b, char **str);
t_lst			*op_pb_secure(t_lst *list_a, t_lst *list_b);
int				get_med(t_lst *a, int end);
int				*get_tab(t_lst *a, int end);
void			q_sort(t_lst **a, t_lst **b, int end, char **str);
int				part_list(t_lst **list_a, t_lst **list_b, char **str, int end);
void			depop_b(t_lst *a, t_lst *b, int size, char **str);
void			sort_a(t_lst **list_a, t_lst **list_b, char **str);
void			insert_a(t_lst **a, t_lst **b, char *str);
void			insert_b(t_lst **a, t_lst **b, char **str);
int				get_swap(t_lst *list_a);
char			*insert_sort(t_lst *list_a, t_lst *list_b, char *str);
void			q_sort2(t_lst **a, t_lst **b, int begin, int end, char **str);

int				get_med_(t_lst *a, int start, int end);
int				*get_tab_(t_lst *a, int start, int end);
int				part_list_(t_lst **list_a, t_lst **list_b,
				char **str, int start, int end);
void			mix_sort(t_lst **a, t_lst **b, int end, char **str);
int				get_min_pivot(t_elem *elem_a, t_lst **list_a);
int				free_exit(char *str, t_lst *list_a, t_lst *list_b);
void			free_exit_check(t_lst *list_a, t_lst *list_b);
void			sort_pivot_smart(t_lst **a, t_lst **b, char **str);
int				get_iter_bis(t_elem *e_a, t_lst **list_a, t_elem *e_b);
int				little_sort(t_lst **a, char **str);
int				part_list_b(t_lst **list_a, t_lst **list_b, char **str,
				int end);
void			pa_inst(char **str);
void			rb_inst(char **str);
#endif
