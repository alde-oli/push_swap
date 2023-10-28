/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:32:44 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/28 09:39:53 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_node *stack)
{
	if (!stack)
		return (0);
	while (stack && stack->next)
	{
		if (stack->v > stack->next->v)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_is_rev_sorted(t_node *stack)
{
	if (!stack)
		return (0);
	while (stack && stack->next)
	{
		if (stack->v < stack->next->v)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_find_value(t_node **s_a, t_node **s_b, int value, char name)
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
		current = current->next;
		position++;
	}
	return (0);
}

void	ft_v_to_top(t_node **s_a, t_node **s_b, int v, char name)
{
	int	len;
	int	pos;

	if (name == 'a')
		len = ft_stack_len(*s_a);
	else
		len = ft_stack_len(*s_b);
	pos = ft_find_value(s_a, s_b, v, name);
	if (len == 1 || pos == 1)
		return ;
	while (pos > (len / 2) && pos <= len)
	{
		ft_do_rrotate(s_a, s_b, name);
		pos++;
	}
	while (pos <= (len / 2) && pos - 1 > 0)
	{
		ft_do_rotate(s_a, s_b, name);
		pos--;
	}
}
