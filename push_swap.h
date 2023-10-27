/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:32:23 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/26 16:22:38 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_node{
	int				v;
	struct s_node	*next;
}	t_node;

//stacks_mgmt
t_node		*ft_init_stack(char **s, int len);
int			ft_stack_len(t_node *stack);
t_node		*ft_stack_dup(t_node *stack);
void		ft_free_stacks(t_node **stack_a, t_node **stack_b);
//operations
void		ft_swap(t_node **stack);
void		ft_push(t_node **src, t_node **dest);
void		ft_rotate(t_node **stack);
void		ft_reverse_rotate(t_node **stack);
//operations_mgmt
void		ft_do_swap(t_node **s_a, t_node **s_b, char name);
void		ft_do_push(t_node **s_a, t_node **s_b, char name);
void		ft_do_rotate(t_node **s_a, t_node **s_b, char name);
void		ft_do_rrotate(t_node **s_a, t_node **s_b, char name);
//sorts
void		ft_sort_three(t_node **stack);
void		ft_sort_four(t_node **stack_a, t_node **stack_b);
void		ft_sort_five(t_node **stack_a, t_node **stack_b);
void		ft_sort_radix(t_node **stack_a, t_node **stack_b);
//sort_utils
int			ft_is_sorted(t_node *stack);
int			ft_is_rev_sorted(t_node *stack);
int			ft_find_value(t_node **s_a, t_node **s_b, int value, char name);
void		ft_v_to_top(t_node **s_a, t_node **s_b, int v, char name);
//simplify_values
void		ft_simplify_stack(t_node **stack);
//print_stacks
void		ft_print_stacks(t_node *s_a, t_node *s_b);
//utils
void		ft_putnbr(int n);
int			ft_atoi(char *s);
long long	ft_atoll(char *s);
//check_input
int			ft_is_duplicate(t_node *stack);
int			ft_check_input(char **argv, int nb);
#endif