/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:01:40 by alde-oli          #+#    #+#             */
/*   Updated: 2024/01/04 09:38:18 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "bonus.h"

static int	ft_exec_order(int order, t_node **s_a, t_node **s_b)
{
	if (order == 0)
		return (push(s_b, s_a));
	else if (order == 1)
		return (push(s_a, s_b));
	else if (order == 2)
		return (swap(s_a));
	else if (order == 3)
		return (swap(s_b));
	else if (order == 4)
		return (swap(s_a) + swap(s_b));
	else if (order == 5)
		return (rotate(s_a));
	else if (order == 6)
		return (rotate(s_b));
	else if (order == 7)
		return (rotate(s_a) + rotate(s_b));
	else if (order == 8)
		return (revrotate(s_a));
	else if (order == 9)
		return (revrotate(s_b));
	else if (order == 10)
		return (revrotate(s_a) + revrotate(s_b));
	return (0);
}

static void	execute_orders(t_node **s_a, t_node **s_b)
{
	int	order;

	order = get_instruct();
	while (order != -2)
	{
		if (order == -1)
		{
			write(2, "Error\n", 6);
			free_stacks(s_a, s_b);
			return ;
		}
		else
			ft_exec_order(order, s_a, s_b);
		order = get_instruct();
	}
	if (is_sorted(*s_a) && !*s_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stacks(s_a, s_b);
}

int	initialize_and_sort(int arg_count, char **args, t_node **s_a, t_node **s_b)
{
	if (!ft_check_input(args, arg_count))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	*s_a = ft_init_stack(args, arg_count, s_b);
	if (ft_is_duplicate(*s_a))
	{
		write(2, "Error\n", 6);
		free_stacks(s_a, s_b);
		return (0);
	}
	execute_orders(s_a, s_b);
	return (1);
}

int	main(int argc, char **argv)
{
	t_node	*s_a;
	t_node	*s_b;
	int		arg_count;
	int		need_free;

	s_a = NULL;
	s_b = NULL;
	need_free = 0;
	if (argc > 1)
	{
		if (argc == 2)
		{
			argv = ft_split(argv[1]);
			arg_count = ft_tab_len(argv);
			need_free = 1;
		}
		else
		{
			argv = argv + 1;
			arg_count = argc - 1;
		}
		if (!initialize_and_sort(arg_count, argv, &s_a, &s_b) && need_free)
			free_tab(argv);
	}
	return (0);
}
