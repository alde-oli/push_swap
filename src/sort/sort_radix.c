/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:10:34 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/31 14:04:43 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_bytes(int len)
{
	int	max_bytes;

	max_bytes = 0;
	while ((len >> max_bytes) != 0)
		max_bytes++;
	return (max_bytes);
}

void	ft_sort_radix(t_node **s_a, t_node **s_b, int bytes)
{
	int	len;

	len = stack_len(*s_a);
	if (bytes >= max_bytes(len))
		return ;
	while (len)
	{
		if (((*s_a)->v >> bytes) & 1)
			dorotate(s_a, s_b, 'a');
		else
			dopush(s_a, s_b, 'b');
		len--;
	}
	while (*s_b)
		dopush(s_a, s_b, 'a');
	ft_sort_radix(s_a, s_b, bytes + 1);
}
