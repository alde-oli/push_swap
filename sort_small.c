/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:32:44 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/27 16:33:06 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_node **stack)
{
	if ((*stack)->v < (*stack)->next->next->v
		&& (*stack)->next->next->v < (*stack)->next->v)
	{
		ft_do_rrotate(stack, NULL, 'a');
		ft_do_swap(stack, NULL, 'a');
	}
	else if ((*stack)->next->v < (*stack)->v
		&& (*stack)->v < (*stack)->next->next->v)
		ft_do_swap(stack, NULL, 'a');
	else if ((*stack)->next->v < (*stack)->next->next->v
		&& (*stack)->next->next->v < (*stack)->v)
	{
		ft_do_rotate(stack, NULL, 'a');
	}
	else if ((*stack)->next->next->v < (*stack)->v
		&& (*stack)->v < (*stack)->next->v)
		ft_do_rrotate(stack, NULL, 'a');
	else if ((*stack)->next->next->v < (*stack)->next->v
		&& (*stack)->next->v < (*stack)->v)
	{
		ft_do_rotate(stack, NULL, 'a');
		ft_do_swap(stack, NULL, 'a');
	}
}

void	ft_sort_four(t_node **stack_a, t_node **stack_b)
{
	if ((*stack_a)->v == 2 && (*stack_a)->next->v == 1)
		ft_do_swap(stack_a, stack_b, 'a');
	else
		ft_v_to_top(stack_a, stack_b, 1, 'a');
	if (ft_is_sorted(*stack_a))
		return ;
	ft_do_push(stack_a, stack_b, 'b');
	ft_sort_three(stack_a);
	ft_do_push(stack_a, stack_b, 'a');
}

void	ft_sort_five(t_node **stack_a, t_node **stack_b)
{
	if ((*stack_a)->v == 2 && (*stack_a)->next->v == 1)
		ft_do_swap(stack_a, stack_b, 'a');
	else if ((*stack_a)->v == 1
		&& (*stack_a)->next->next->next->next->v == 2)
		ft_do_rrotate(stack_a, stack_b, 'a');
	else
	{
		ft_v_to_top(stack_a, stack_b, 1, 'a');
		if (ft_is_sorted(*stack_a))
			return ;
		ft_do_push(stack_a, stack_b, 'b');
		ft_sort_four(stack_a, stack_b);
		ft_do_push(stack_a, stack_b, 'a');
	}
	if (!ft_is_sorted(*stack_a))
	{
		if (ft_stack_len(*stack_a) != 3)
		{
			ft_do_push(stack_a, stack_b, 'b');
			ft_do_push(stack_a, stack_b, 'b');
		}
		ft_sort_three(stack_a);
		ft_do_push(stack_a, stack_b, 'a');
		ft_do_push(stack_a, stack_b, 'a');
	}
}
