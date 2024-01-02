/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:32:44 by alde-oli          #+#    #+#             */
/*   Updated: 2024/01/02 17:42:36 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_node **stack)
{
	t_node	*temp1;
	t_node	*temp2;

	if (stack && *stack && (*stack)->nxt)
	{
		temp1 = (*stack)->nxt;
		temp2 = (*stack)->nxt->nxt;
		temp1->nxt = *stack;
		(*stack)->nxt = temp2;
		*stack = temp1;
	}
	return (0);
}

int	push(t_node **src, t_node **dest)
{
	t_node	*temp;

	if (*src)
	{
		temp = *src;
		*src = (*src)->nxt;
		temp->nxt = *dest;
		*dest = temp;
	}
	return (0);
}

int	rotate(t_node **stack)
{
	t_node	*temp1;
	t_node	*temp2;

	if ((*stack)->nxt)
	{
		temp1 = (*stack)->nxt;
		temp2 = *stack;
		while (temp2->nxt)
			temp2 = temp2->nxt;
		temp2->nxt = *stack;
		temp2->nxt->nxt = NULL;
		*stack = temp1;
	}
	return (0);
}

int	revrotate(t_node **stack)
{
	t_node	*temp1;
	t_node	*temp2;

	if ((*stack)->nxt)
	{
		temp1 = *stack;
		while (temp1->nxt->nxt)
			temp1 = temp1->nxt;
		temp2 = temp1->nxt;
		temp1->nxt = NULL;
		temp2->nxt = *stack;
		*stack = temp2;
	}
	return (0);
}
