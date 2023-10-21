/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:32:44 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/21 15:52:03 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_init_stack(char **s)
{
	t_node	*stack;
	t_node	*new_node;

	if (!s | !*s)
		return (NULL);
	new_node = malloc(sizeof(t_node));
	new_node->v = atoi(*s);
	new_node->next = NULL;
	s++;
	stack = new_node;
	while (*s)
	{
		new_node->next = malloc(sizeof(t_node));
		new_node = new_node->next;
		new_node->v = atoi(*s);
		new_node->next = NULL;
		s++;
	}
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

void	ft_print_stacks(t_node *stack_a, t_node *stack_b)
{
	int	a;
	int	b;

	a = ft_stack_len(stack_a);
	b = ft_stack_len(stack_b);
	printf("\n\n{[  STACK A  ]} | {[  STACK B  ]}\n -------------     -------------\n");
	while ((a > 0 || b > 0) && a != b)
	{
		if (a > b)
		{
			printf(" [%11d]  |\n", stack_a->v);
			stack_a = stack_a->next;
			a--;
		}
		else
		{
			printf("                |  [%11d]\n", stack_b->v);
			stack_b = stack_b->next;
			b--;
		}
	}
	while (a > 0)
	{
		printf(" [%11d]  |  [%11d]\n", stack_a->v, stack_b->v);
		stack_a = stack_a->next;
		stack_b = stack_b->next;
		a--;
	}
	printf(" -------------     -------------\n");
}

int	main(int argc, char **argv)
{
	t_node	*stack_a = ft_init_stack(argv + 1);
	t_node	*stack_b = stack_a->next->next;
	ft_print_stacks(stack_a, stack_b);
}
