/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:52:48 by alde-oli          #+#    #+#             */
/*   Updated: 2024/01/07 17:24:17 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//0 == ra && rrb                  1 == rra && rb
//2 == ra && rb && ra >= rb       3 == ra && rb && ra < rb, 
//4 == rra && rrb && rra >= rrb   5 == rra && rrb && rra < rrb
static int	best_rota(t_node *s_a, t_node *s_b, int v)
{
	const int	target = target_a(s_b, v);
	const int	c_v[2] = {cost_with_r(s_a, v), cost_with_rr(s_a, v)};
	const int	c_t[2] = {cost_with_r(s_b, target),
		cost_with_rr(s_b, target)};
	int			ans[4];

	ans[0] = c_v[0] + c_t[1];
	ans[1] = c_v[1] + c_t[0];
	ans[2] = (c_v[0]) * (c_v[0] >= c_t[0]) + (c_t[0]) * (c_t[0] > c_v[0]);
	ans[3] = (c_v[1]) * (c_v[1] >= c_t[1]) + (c_t[1]) * (c_t[1] > c_v[1]);
	if (ans[0] <= ans[1] && ans[0] <= ans[2] && ans[0] <= ans[3])
		return (0);
	else if (ans[1] <= ans[0] && ans[1] <= ans[2] && ans[1] <= ans[3])
		return (1);
	else if (ans[2] <= ans[0] && ans[2] <= ans[1] && ans[2] <= ans[3])
		return (2 * (c_v[0] >= c_t[0]) + 3 * (c_v[0] < c_t[0]));
	else
		return (4 * (c_v[1] >= c_t[1]) + 5 * (c_v[1] < c_t[1]));
}

//nb operations to put v and it's target on top of stack a

static void	together_to_top(t_node **s_a, t_node **s_b, int v_a, int v_b)
{
	const int	wich_rota = best_rota(*s_a, *s_b, v_a);
	int			nb;

	if (wich_rota < 2)
		return ;
	if (wich_rota == 2)
		nb = cost_with_r(*s_b, v_b);
	else if (wich_rota == 3)
		nb = cost_with_r(*s_a, v_a);
	else if (wich_rota == 4)
		nb = cost_with_rr(*s_b, v_b);
	else
		nb = cost_with_rr(*s_a, v_a);
	while (nb > 0)
	{
		if (wich_rota < 4)
			dorotate(s_a, s_b, 'r');
		else
			dorevrotate(s_a, s_b, 'r');
		nb--;
	}
}

//find cheapest v to put with it's target on top of stack b
static int	cheapest_b(t_node **s_a, t_node **s_b)
{
	t_node	*tmp;
	int		cheapest_v;
	int		cheapest_cost;
	int		cost;

	tmp = *s_a;
	cheapest_v = (*s_a)->v;
	cheapest_cost = cost_b(*s_a, *s_b, cheapest_v);
	while (tmp)
	{
		cost = cost_b(*s_a, *s_b, tmp->v);
		if (cost < cheapest_cost)
		{
			cheapest_v = tmp->v;
			cheapest_cost = cost;
		}
		tmp = tmp->nxt;
	}
	together_to_top(s_a, s_b, cheapest_v, target_a(*s_b, cheapest_v));
	v_to_top(s_a, s_b, cheapest_v, 'a');
	v_to_top(s_a, s_b, target_a(*s_b, cheapest_v), 'b');
	dopush(s_a, s_b, 'b');
	return (cheapest_v);
}

//find cheapest v to put with it's target on top of stack a
static int	cheapest_a(t_node **s_a, t_node **s_b)
{
	int	cheapest_v;

	cheapest_v = (*s_b)->v;
	together_to_top(s_a, s_b, target_a(*s_b, cheapest_v), cheapest_v);
	v_to_top(s_a, s_b, cheapest_v, 'b');
	v_to_top(s_a, s_b, target_a(*s_a, cheapest_v), 'a');
	dopush(s_a, s_b, 'a');
	return (cheapest_v);
}

void	sort_turk(t_node **s_a, t_node **s_b)
{
	dopush(s_a, s_b, 'b');
	dopush(s_a, s_b, 'b');
	if ((*s_b)->v > (*s_b)->nxt->v)
		doswap(s_a, s_b, 'b');
	while (stack_len(*s_a) > 3)
		cheapest_b(s_a, s_b);
	sort_three(s_a);
	while (*s_b)
		cheapest_a(s_a, s_b);
	v_to_top(s_a, s_b, 1, 'a');
}
