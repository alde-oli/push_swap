/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:32:44 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/25 21:34:36 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->v > stack->next->v)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_find_value(t_node **stack, int value)
{
	t_node	*current;
	int		position;

	current = *stack;
	position = 1;
	while (current)
	{
		if (current->v == value)
			return (position);
		current = current->next;
		position++;
	}
	return (0);
}
