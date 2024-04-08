/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:27:12 by alde-oli          #+#    #+#             */
/*   Updated: 2024/01/04 09:36:17 by alde-oli         ###   ########.fr       */
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

static ssize_t	read_input(char *input, size_t size)
{
	ssize_t	nread;
	size_t	i;

	i = 0;
	ft_memset(input, 0, size);
	while (i < size - 1)
	{
		nread = read(STDIN_FILENO, &input[i], 1);
		if (nread <= 0 && i == 0)
			return (-2);
		else if (nread <= 0 && i != 0)
			return (i);
		if (input[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

int	get_instruct(void)
{
	char	input[5];
	ssize_t	read_result;

	read_result = read_input(input, sizeof(input));
	if (read_result < 0)
		return (read_result);
	if (read_result < (ssize_t) sizeof(input) - 1 || input[read_result] == '\n')
	{
		input[read_result] = '\0';
		return (get_instruction_index(input));
	}
	return (-1);
}
