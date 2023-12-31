/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_mgmt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:32:44 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/31 14:12:45 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_init_stack(char **s, int len, t_node **s_b)
{
	t_node	*stack;
	t_node	*new_node;

	stack = NULL;
	while (len > 0)
	{
		new_node = malloc(sizeof(t_node));
		if (!new_node)
		{
			free_stacks(&stack, NULL);
			return (NULL);
		}
		new_node->v = ft_atoi(s[len - 1]);
		new_node->nxt = stack;
		stack = new_node;
		len--;
	}
	ft_simplify_stack(&stack);
	*s_b = NULL;
	return (stack);
}

int	stack_len(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->nxt;
	}
	return (i);
}

void	free_stacks(t_node **s_a, t_node **s_b)
{
	t_node	*temp;

	if (s_a && *s_a)
	{
		while (*s_a)
		{
			temp = (*s_a)->nxt;
			free(*s_a);
			*s_a = NULL;
			*s_a = temp;
		}
		s_a = NULL;
	}
	if (s_b && *s_b)
	{
		while (*s_b)
		{
			temp = (*s_b)->nxt;
			free(*s_b);
			*s_b = NULL;
			*s_b = temp;
		}
		s_b = NULL;
	}
}
