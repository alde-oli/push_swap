/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:36:18 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/26 16:27:47 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_node **stack_a, t_node **stack_b)
{
	int	stack_len;

	stack_len = ft_stack_len(*stack_a);
	if (stack_len == 2 && (*stack_a)->v > (*stack_a)->next->v)
		ft_do_swap(stack_a, stack_b, 'a');
	else if (stack_len == 3)
		ft_sort_three(stack_a);
	else if (stack_len > 3)
		ft_sort_radix(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc > 1)
	{
		if (ft_check_input(argv + 1, argc - 1))
		{
			stack_a = ft_init_stack(argv + 1, argc - 1);
			if (!ft_is_duplicate(stack_a))
			{
				stack_b = NULL;
				ft_simplify_stack(&stack_a);
				if (!ft_is_sorted(stack_a))
					ft_sort(&stack_a, &stack_b);
			}
			else
				write(2, "Error\n", 6);
			ft_free_stacks(&stack_a, &stack_b);
		}
	}
}
