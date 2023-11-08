/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:36:18 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/29 00:02:59 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_node **stack_a, t_node **stack_b)
{
	int	stack_len;

	stack_len = ft_stack_len(*stack_a);
	if (ft_is_duplicate(*stack_a))
	{
		write(2, "Error\n", 6);
		ft_free_stacks(stack_a, stack_b);
		return ;
	}
	if (ft_is_sorted(*stack_a))
	{
		ft_free_stacks(stack_a, stack_b);
		return ;
	}
	if (stack_len == 2 && (*stack_a)->v > (*stack_a)->next->v)
		ft_do_swap(stack_a, stack_b, 'a');
	else if (stack_len == 3)
		ft_sort_three(stack_a);
	else if (stack_len == 4)
		ft_sort_four(stack_a, stack_b);
	else if (stack_len == 5)
		ft_sort_five(stack_a, stack_b);
	else if (stack_len > 3)
		ft_sort_radix(stack_a, stack_b, 0);
	ft_free_stacks(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc > 1)
	{
		if (argc == 2)
		{
			argv = ft_split(argv[1]);
			if (ft_check_input(argv, ft_tab_len(argv)))
			{
				stack_a = ft_init_stack(argv, ft_tab_len(argv), &stack_b);
				ft_sort(&stack_a, &stack_b);
			}
			else
				write(2, "Error\n", 6);
			ft_free_tab(argv);
		}
		else if (ft_check_input(argv + 1, argc - 1))
		{
			stack_a = ft_init_stack(argv + 1, argc - 1, &stack_b);
			ft_sort(&stack_a, &stack_b);
		}
		else
			write(2, "Error\n", 6);
	}
}
