/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:32:44 by alde-oli          #+#    #+#             */
/*   Updated: 2024/01/08 09:06:44 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_wait(void)
{
	unsigned long	i;

	i = 50000000;
	while (i)
		i--;
}

static t_node	*ft_print_a(t_node *s_a, int *a, int *b)
{
	while (*a > *b)
	{
		ft_putnbr(s_a->v);
		write(1, "  |\n", 4);
		s_a = s_a->nxt;
		*a -= 1;
	}
	return (s_a);
}

static t_node	*ft_print_b(t_node *s_b, int *a, int *b)
{
	while (*a < *b)
	{
		write(1, "                | ", 19);
		ft_putnbr(s_b->v);
		write(1, "\n", 1);
		s_b = s_b->nxt;
		*b -= 1;
	}
	return (s_b);
}

static void	ft_print_both(t_node *s_a, t_node *s_b, int a)
{
	while (a > 0)
	{
		ft_putnbr(s_a->v);
		write(1, "  | ", 5);
		ft_putnbr(s_b->v);
		write(1, "\n", 1);
		s_a = s_a->nxt;
		s_b = s_b->nxt;
		a--;
	}
}

void	ft_print_stacks(t_node *s_a, t_node *s_b)
{
	static int	operations = 0;
	int			a;
	int			b;

	a = stack_len(s_a);
	b = stack_len(s_b);
	write(1, "Operations: ", 12);
	ft_putnbr(operations);
	write(1, "\n", 1);
	write(1, "\n{[  STACK A  ]} | {[  STACK B  ]}\n", 36);
	if (a > b)
		s_a = ft_print_a(s_a, &a, &b);
	else if (a < b)
		s_b = ft_print_b(s_b, &a, &b);
	if (a && b)
		ft_print_both(s_a, s_b, a);
	write(1, "\n\n", 2);
	ft_wait();
	operations += 1;
}
