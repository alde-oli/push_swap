/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:36:18 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/24 12:07:05 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc > 1)
	{
		if (ft_check_input(argv + 1, argc - 1))
		{
			stack_a = ft_init_stack(argv + 1);
			if (!ft_is_duplicate(stack_a))
			{
				stack_b = NULL;
				stack_a = ft_sort(&stack_a, &stack_b);
			}
			else
				write(2, "Error\n", 6);
			ft_free_stacks(&stack_a, &stack_b);
		}
		else
			write(2, "Error\n", 6);
	}
}
