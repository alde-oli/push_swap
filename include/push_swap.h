/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:32:23 by alde-oli          #+#    #+#             */
/*   Updated: 2024/01/08 09:10:28 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_node
{
	int				v;
	struct s_node	*nxt;
}	t_node;

//stacks_mgmt
t_node		*ft_init_stack(char **s, int len, t_node **s_b);
int			stack_len(t_node *stack);
void		free_stacks(t_node **s_a, t_node **s_b);
//operations
int			swap(t_node **stack);
int			push(t_node **src, t_node **dest);
int			rotate(t_node **stack);
int			revrotate(t_node **stack);
//operations_mgmt
void		doswap(t_node **s_a, t_node **s_b, char name);
void		dopush(t_node **s_a, t_node **s_b, char name);
void		dorotate(t_node **s_a, t_node **s_b, char name);
void		dorevrotate(t_node **s_a, t_node **s_b, char name);
//sorts
void		sort_three(t_node **stack);
void		sort_four(t_node **s_a, t_node **s_b);
void		sort_five(t_node **s_a, t_node **s_b);
void		ft_sort_radix(t_node **s_a, t_node **s_b, int bytes);
void		sort_turk(t_node **s_a, t_node **s_b);
void		sort_custom(t_node **s_a, t_node **s_b);
//sort_utils
int			is_sorted(t_node *stack);
int			find_value(t_node **s_a, t_node **s_b, int value, char name);
void		v_to_top(t_node **s_a, t_node **s_b, int v, char name);
int			cost_with_r(t_node *s, int v);
int			cost_with_rr(t_node *s, int v);
int			target_b(t_node *s, int v);
int			target_a(t_node *s, int v);
int			cost_b(t_node *s_a, t_node *s_b, int v);
//simplify_values
void		ft_simplify_stack(t_node **stack);
//print_stacks
void		ft_print_stacks(t_node *s_a, t_node *s_b);
//utils
void		ft_putnbr(int n);
int			ft_atoi(char *s);
long long	ft_atoll(char *s);
char		**ft_split(char const *s);
int			ft_tab_len(char **tab);
void		free_tab(char **tab);
int			find_max(t_node *stack);
int			find_min(t_node *stack);
void		ft_memset(void *b, int c, size_t len);
//check_input
int			ft_is_duplicate(t_node *stack);
int			ft_check_input(char **argv, int nb);
#endif