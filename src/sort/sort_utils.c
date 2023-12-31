/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:32:44 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/31 15:44:16 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *stack)
{
	if (!stack)
		return (0);
	while (stack && stack->nxt)
	{
		if (stack->v > stack->nxt->v)
			return (0);
		stack = stack->nxt;
	}
	return (1);
}

int	find_value(t_node **s_a, t_node **s_b, int value, char name)
{
	t_node	*current;
	int		position;

	if (name == 'a')
		current = *s_a;
	else
		current = *s_b;
	position = 1;
	while (current)
	{
		if (current->v == value)
			return (position);
		current = current->nxt;
		position++;
	}
	return (0);
}

void	v_to_top(t_node **s_a, t_node **s_b, int v, char name)
{
	int	len;
	int	pos;

	if (name == 'a')
		len = stack_len(*s_a);
	else
		len = stack_len(*s_b);
	pos = find_value(s_a, s_b, v, name);
	if (len == 1 || pos == 1)
		return ;
	while (pos > (len / 2 + len % 2) && pos <= len)
	{
		dorevrotate(s_a, s_b, name);
		pos++;
	}
	while (pos <= (len / 2 + len % 2) && pos - 1 > 0)
	{
		dorotate(s_a, s_b, name);
		pos--;
	}
}
