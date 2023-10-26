/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:10:34 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/26 16:34:22 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_len_len(int len)
{
	int	len_len;

	len_len = 1;
	while (len > 9)
	{
		len /= 10;
		len_len += 1;
	}
	return (len_len);
}

int	ft_ten_power(int digit)
{
	int	result;

	result = 1;
	while (digit > 0)
	{
		result *= 10;
		digit--;
	}
	return (result);
}

void	ft_sort_digit_to_b(t_node **s_a, t_node **s_b, int digit)
{
	int		v;
	t_node	*current;
	int		pos;

	v = 0;
	while (v <= 9)
	{
		current = *s_a;
		while (current)
		{
			if ((current->v / ft_ten_power(digit)) % 10 == v)
			{
				ft_v_to_top(s_a, s_b, current->v, 'a');
				ft_do_push(s_a, s_b, 'b');
				current = *s_a;
			}
		}
		v++;
	}
}

void	ft_sort_digit_to_a(t_node **s_a, t_node **s_b, int digit)
{
	int		v;
	t_node	*current;
	int		pos;

	v = 0;
	while (v <= 9)
	{
		current = *s_a;
		while (current)
		{
			if ((current->v / ft_ten_power(digit)) % 10 == v)
			{
				ft_v_to_top(s_a, s_b, current->v, 'b');
				ft_do_push(s_a, s_b, 'a');
				current = *s_a;
			}
		}
		v++;
	}
}

void	ft_transfer(t_node **s_a, t_node **s_b)
{
	while (*s_b)
	{
		ft_do_push(s_a, s_b, 'a');
	}
}

void	ft_sort_radix(t_node **stack_a, t_node **stack_b)
{
	int	len;
	int	max;
	int	digit;

	len = ft_stack_len(*stack_a);
	max = ft_len_len(len);
	digit = 1;
	while (digit <= max && (ft_is_sorted(*stack_a) || ft_is_rev_sorted(*stack_b)))
	{
		if (digit % 2)
			ft_sort_digit_to_a(stack_a, stack_b, digit);
		else
			ft_sort_digit_to_b(stack_a, stack_b, digit);
		digit ++;
		printf("stack_a: %d\n", ft_stack_len(*stack_a));
	}
	if (!*stack_a)
		ft_transfer(stack_a, stack_b);
}
