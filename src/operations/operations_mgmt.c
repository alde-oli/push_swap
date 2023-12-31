/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_mgmt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:20:43 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/31 13:58:08 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	doswap(t_node **s_a, t_node **s_b, char name)
{
	if (name == 'a')
	{
		swap(s_a);
		write(1, "sa\n", 3);
	}
	if (name == 'b')
	{
		swap(s_b);
		write(1, "sb\n", 3);
	}
	if (name == 's')
	{
		swap(s_a);
		swap(s_b);
		write(1, "ss\n", 3);
	}
}

void	dopush(t_node **s_a, t_node **s_b, char name)
{
	if (name == 'a')
	{
		push(s_b, s_a);
		write(1, "pa\n", 3);
	}
	if (name == 'b')
	{
		push(s_a, s_b);
		write(1, "pb\n", 3);
	}
}

void	dorotate(t_node **s_a, t_node **s_b, char name)
{
	if (name == 'a')
	{
		rotate(s_a);
		write(1, "ra\n", 3);
	}
	if (name == 'b')
	{
		rotate(s_b);
		write(1, "rb\n", 3);
	}
	if (name == 'r')
	{
		rotate(s_a);
		rotate(s_b);
		write(1, "rr\n", 3);
	}
}

void	dorevrotate(t_node **s_a, t_node **s_b, char name)
{
	if (name == 'a')
	{
		revrotate(s_a);
		write(1, "rra\n", 4);
	}
	if (name == 'b')
	{
		revrotate(s_b);
		write(1, "rrb\n", 4);
	}
	if (name == 'r')
	{
		revrotate(s_a);
		revrotate(s_b);
		write(1, "rrr\n", 4);
	}
}
