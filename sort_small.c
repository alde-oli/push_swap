/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:32:44 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/26 14:22:55 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_node **stack)
{
	if ((*stack)->next->v < (*stack)->next->next->v)
	{
		if ((*stack)->v > (*stack)->next->next->v)
			ft_do_rotate(stack, NULL, 'a');
		else if ((*stack)->v > (*stack)->next->v)
			ft_do_swap(stack, NULL, 'a');
	}
	else
	{
		if ((*stack)->v > (*stack)->next->v
			&& (*stack)->v < (*stack)->next->next->v)
			ft_do_swap(stack, NULL, 'a');
		else if ((*stack)->v > (*stack)->next->next->v)
		{
			ft_do_swap(stack, NULL, 'a');
			ft_do_rrotate(stack, NULL, 'a');
		}
		else
		{
			ft_do_rrotate(stack, NULL, 'a');
			ft_do_swap(stack, NULL, 'a');
		}
	}
}
