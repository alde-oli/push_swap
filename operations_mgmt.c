/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_mgmt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:20:43 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/24 10:33:59 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_swap(t_node **s_a, t_node **s_b, char name)
{
	if (name == 'a')
	{
		ft_swap(s_a);
		write(1, "sa\n", 3);
	}
	if (name == 'b')
	{
		ft_swap(s_b);
		write(1, "sb\n", 3);
	}
	if (name == 's')
	{
		ft_swap(s_a);
		ft_swap(s_b);
		write(1, "ss\n", 3);
	}
}

void	ft_do_push(t_node **s_a, t_node **s_b, char name)
{
	if (name == 'a')
	{
		ft_push(s_b, s_a);
		write(1, "pa\n", 3);
	}
	if (name == 'b')
	{
		ft_push(s_a, s_b);
		write(1, "pb\n", 3);
	}
}

void	ft_do_rotate(t_node **s_a, t_node **s_b, char name)
{
	if (name == 'a')
	{
		ft_rotate(s_a);
		write(1, "ra\n", 3);
	}
	if (name == 'b')
	{
		ft_rotate(s_b);
		write(1, "rb\n", 3);
	}
	if (name == 'r')
	{
		ft_rotate(s_a);
		ft_rotate(s_b);
		write(1, "rr\n", 3);
	}
}

void	ft_do_rrotate(t_node **s_a, t_node **s_b, char name)
{
	if (name == 'a')
	{
		ft_reverse_rotate(s_a);
		write(1, "rra\n", 4);
	}
	if (name == 'b')
	{
		ft_reverse_rotate(s_b);
		write(1, "rrb\n", 4);
	}
	if (name == 'r')
	{
		ft_reverse_rotate(s_a);
		ft_reverse_rotate(s_b);
		write(1, "rrr\n", 4);
	}
}
