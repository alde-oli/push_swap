/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_mgmt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:32:44 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/09 10:53:15 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_init_stack(char **s, int len, t_node **stack_b)
{
	t_node	*stack;
	t_node	*new_node;

	stack = NULL;
	while (len > 0)
	{
		new_node = malloc(sizeof(t_node));
		if (!new_node)
		{
			ft_free_stacks(&stack, NULL);
			return (NULL);
		}
		new_node->v = ft_atoi(s[len - 1]);
		new_node->next = stack;
		stack = new_node;
		len--;
	}
	ft_simplify_stack(&stack);
	*stack_b = NULL;
	return (stack);
}

int	ft_stack_len(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

static t_node	*ft_new_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->v = value;
	new_node->next = NULL;
	return (new_node);
}

void	ft_free_stacks(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	if (stack_a && *stack_a)
	{
		while (*stack_a)
		{
			temp = (*stack_a)->next;
			free(*stack_a);
			*stack_a = NULL;
			*stack_a = temp;
		}
		stack_a = NULL;
	}
	if (stack_b && *stack_b)
	{
		while (*stack_b)
		{
			temp = (*stack_b)->next;
			free(*stack_b);
			*stack_b = NULL;
			*stack_b = temp;
		}
		stack_b = NULL;
	}
}
