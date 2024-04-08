/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:36:18 by alde-oli          #+#    #+#             */
/*   Updated: 2024/01/07 13:45:41 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_node **s_a, t_node **s_b)
{
	int	len;

	len = stack_len(*s_a);
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
	else if (len < 300)
		sort_turk(s_a, s_b);
	else
		sort_custom(s_a, s_b);
	free_stacks(s_a, s_b);
}

static int	initialize_and_sort(int arg_count, char **args,
	t_node **s_a, t_node **s_b)
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
	ft_sort(s_a, s_b);
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
