/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:36:18 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/31 17:48:26 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_node **s_a, t_node **s_b)
{
	int	len;

	len = stack_len(*s_a);
	if (ft_is_duplicate(*s_a))
	{
		write(2, "Error\n", 6);
		free_stacks(s_a, s_b);
		return ;
	}
	if (is_sorted(*s_a))
	{
		free_stacks(s_a, s_b);
		return ;
	}
	if (len == 2 && (*s_a)->v > (*s_a)->nxt->v)
		doswap(s_a, s_b, 'a');
	else if (len == 3)
		sort_three(s_a);
	else if (len == 4)
		sort_four(s_a, s_b);
	else if (len == 5)
		sort_five(s_a, s_b);
	else if (len > 3)
		ft_sort_radix(s_a, s_b, 0);
	free_stacks(s_a, s_b);
}

int	main(int argc, char **argv)
{
	t_node	*s_a;
	t_node	*s_b;

	if (argc > 1)
	{
		if (argc == 2)
		{
			argv = ft_split(argv[1]);
			if (ft_check_input(argv, ft_tab_len(argv)))
			{
				s_a = ft_init_stack(argv, ft_tab_len(argv), &s_b);
				ft_sort(&s_a, &s_b);
			}
			else
				write(2, "Error\n", 6);
			free_tab(argv);
		}
		else if (ft_check_input(argv + 1, argc - 1))
		{
			s_a = ft_init_stack(argv + 1, argc - 1, &s_b);
			ft_sort(&s_a, &s_b);
		}
		else
			write(2, "Error\n", 6);
	}
}
