/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:01:40 by alde-oli          #+#    #+#             */
/*   Updated: 2024/01/02 17:40:12 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_instruction_index(const char *input)
{
	const char	*instructions[] = {"pa", "pb", "sa", "sb", "ss",
		"ra", "rb", "rr", "rra", "rrb", "rrr"};
	int			i;
	int			j;
	int			is_match;

	i = 0;
	while (i < 11)
	{
		j = 0;
		is_match = 1;
		while (instructions[i][j] != '\0' && input[j] != '\0')
		{
			if (instructions[i][j] != input[j])
			{
				is_match = 0;
				break ;
			}
			j++;
		}
		if (is_match && instructions[i][j] == '\0' && input[j] == '\0')
			return (i);
		i++;
	}
	return (-1);
}


static int get_instruct(void)
{
    char input[5]; // Augmente la taille pour inclure '\n' et '\0'
    ssize_t nread;
    int i = 0;

    memset(input, 0, 5);
    while (i < 4) { // Permet jusqu'à 3 caractères plus '\n'
        nread = read(STDIN_FILENO, &input[i], 1);
        if (nread <= 0) { // EOF ou erreur
            if (i == 0)
                return -2; // EOF immédiat, aucun caractère lu
            else {
                input[i] = '\0'; // Termine la chaîne si EOF après des caractères
                break;
            }
        }
        if (input[i] == '\n') {
            input[i] = '\0'; // Remplace '\n' par '\0'
            break;
        }
        i++;
    }
    if (i == 4 && input[3] != '\n') // Si 4 caractères ont été lus sans '\n'
        return -1; // Instruction trop longue ou invalide
    return get_instruction_index(input);
}



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
