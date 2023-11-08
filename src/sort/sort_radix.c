/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:10:34 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/28 23:04:33 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_max_bytes(int len)
{
	int	max_bytes;

	max_bytes = 0;
	while ((len >> max_bytes) != 0)
		max_bytes++;
	return (max_bytes);
}

void	ft_sort_radix(t_node **stack_a, t_node **stack_b, int bytes)
{
	int	len;
	int	max_bytes;

	len = ft_stack_len(*stack_a);
	max_bytes = ft_max_bytes(len);
	if (bytes >= max_bytes)
		return ;
	while (len)
	{
		if (((*stack_a)->v >> bytes) & 1)
			ft_do_rotate(stack_a, stack_b, 'a');
		else
			ft_do_push(stack_a, stack_b, 'b');
		len--;
	}
	while (*stack_b)
		ft_do_push(stack_a, stack_b, 'a');
	ft_sort_radix(stack_a, stack_b, bytes + 1);
}
