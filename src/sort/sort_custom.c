/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_custom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 14:17:14 by alde-oli          #+#    #+#             */
/*   Updated: 2024/01/07 13:46:22 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_cat(int v, int len)
{
	const int	fifth = len / 5;

	if (v <= fifth)
		return (1);
	else if (v <= fifth * 2)
		return (2);
	else if (v <= fifth * 3)
		return (3);
	else if (v <= fifth * 4)
		return (4);
	else
		return (5);
}

int	to_b_bottom(t_node **s_a, t_node **s_b, int len, int is_next)
{
	dopush(s_a, s_b, 'b');
	if (is_next && get_cat((*s_a)->v, len) == 3)
	{
		dorotate(s_a, s_b, 'r');
		return (1);
	}
	dorotate(s_a, s_b, 'b');
	return (0);
}

void	first_split(t_node **s_a, t_node **s_b)
{
	const int	len = stack_len(*s_a);
	int			i;

	i = 0;
	while (i < len)
	{
		if (get_cat((*s_a)->v, len) == 1 || get_cat((*s_a)->v, len) == 5)
			i += to_b_bottom(s_a, s_b, len, i < len);
		else if (get_cat((*s_a)->v, len) == 2 || get_cat((*s_a)->v, len) == 4)
			dopush(s_a, s_b, 'b');
		else
			dorotate(s_a, s_b, 'a');
		i++;
	}
}

void	second_split(t_node **s_a, t_node **s_b)
{
	const int	len_b = stack_len(*s_b);
	const int	len = len_b + stack_len(*s_a);
	int			i;

	i = 0;
	while (i < len_b)
	{
		if (get_cat((*s_b)->v, len) > 3)
		{
			dopush(s_a, s_b, 'a');
			dorotate(s_a, s_b, 'a');
		}
		else
			dopush(s_a, s_b, 'a');
		i++;
	}
}

void	sort_custom(t_node **s_a, t_node **s_b)
{
	first_split(s_a, s_b);
	second_split(s_a, s_b);
	sort_turk(s_a, s_b);
}
