/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:56:28 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/24 12:09:30 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_number(char **s, int nb)
{
	int	i;
	int	j;

	i = 0;
	while (i < nb)
	{
		j = 0;
		if (s[i][j] == '-')
			j++;
		while (s[i][j])
		{
			if (s[i][j] < '0' || s[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_is_int(char **s, int nb)
{
	int			len;
	int			i;
	long int	n;

	i = 0;
	while (i < nb)
	{
		len = 0;
		while (s[i][len])
			len++;
		if (len > 11)
			return (1);
		if (ft_atol(s[i]) > 2147483647
			|| ft_atol(s[i] < -2147483648))
			return (1);
		i++;
	}
	return (0);
}

static int	ft_is_duplicate(t_node *stack)
{
	t_node	*b;

	while (stack)
	{
		b = stack->next;
		while (b)
		{
			if (stack->v == b->v)
				return (1);
			b = b->next;
		}
		stack = stack->next;
	}
	return (0);
}

int	ft_check_input(char **argv, int nb)
{
	if (ft_is_number(argv, nb))
		return (0);
	if (ft_is_int(argv, nb))
		return (0);
	return (1);
}
