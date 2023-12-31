/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:52:48 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/31 17:45:35 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//nb operations to put v on top of stack
int	cost_to_top(t_node *s, int v)
{
	const int	len = stack_len(s);
	const int	pos = find_value(s, s, v, 'a');

	if (pos <= (len / 2 + len % 2))
		return (pos - 1);
	else
		return ((len - pos) + 1);
}

//find closest smaller value to v or if not found, biggest value
int	target_b(t_node *s, int v)
{
	const int	max = find_max(s);
	int			closest;

	closest = -1;
	while (s)
	{
		if (s->v < v && s->v > closest)
			closest = s->v;
		s = s->nxt;
	}
	if (closest == -1)
		return (max);
	return (closest);
}

//find closest bigger value to v or if not found, smallest value
int	target_a(t_node *s, int v)
{
	const int	min = find_min(s);
	int			closest;

	closest = -1;
	while (s)
	{
		if (s->v > v && s->v < closest)
			closest = s->v;
		s = s->nxt;
	}
	if (closest == -1)
		return (min);
	return (closest);
}

int	same_rotation(t_node *s_a, t_node *s_b, int val_a, int val_b)
{
	const int	pos_a = find_value(&s_a, &s_b, val_a, 'a');
	const int	pos_b = find_value(&s_a, &s_b, val_b, 'b');
	const int	len_a = stack_len(s_a);
	const int	len_b = stack_len(s_b);

	if (pos_a <= (len_a / 2 + len_a % 2) && pos_b <= (len_b / 2 + len_b % 2))
		return (-1);
	if (pos_a > (len_a / 2 + len_a % 2) && pos_b > (len_b / 2 + len_b % 2))
		return (1);
	return (0);
}

//nb operations to put v and it's target on top of stack b
int	cost_b(t_node *s_a, t_node *s_b, int v)
{
	const int	target = target_b(s_b, v);
	const int	cost_v = cost_to_top(s_a, v);
	const int	cost_target = cost_to_top(s_b, target);

	if (same_rotation(s_a, s_b, v, target))
	{
		if (cost_v > cost_target)
			return (cost_v);
		else if (cost_v < cost_target)
			return (cost_target);
		else
			return (cost_v);
	}
	return (cost_v + cost_target);
}

//nb operations to put v and it's target on top of stack a
int	cost_a(t_node *s_a, t_node *s_b, int v)
{
	const int	target = target_a(s_a, v);
	const int	cost_v = cost_to_top(s_b, v);
	const int	cost_target = cost_to_top(s_a, target);

	if (same_rotation(s_a, s_b, v, target))
	{
		if (cost_v > cost_target)
			return (cost_v);
		else if (cost_v < cost_target)
			return (cost_target);
		else
			return (cost_v);
	}
	return (cost_v + cost_target);
}

void	together_to_top(t_node **s_a, t_node **s_b, int v_a, int v_b)
{
	const int	len_a = stack_len(*s_a);
	const int	len_b = stack_len(*s_b);
	int			p_a;
	int			p_b;

	p_a = find_value(s_a, s_b, v_a, 'a');
	p_b = find_value(s_a, s_b, v_b, 'b');
	if (p_a <= (len_a / 2 + len_a % 2) && p_b <= (len_b / 2 + len_b % 2))
	{
		while (p_a > 1 && p_b > 1)
		{
			dorevrotate(s_a, s_b, 'r');
			p_a--;
			p_b--;
		}
	}
	else if (p_a > (len_a / 2 + len_a % 2) && p_b > (len_b / 2 + len_b % 2))
	{
		while (p_a <= len_a && p_b <= len_b)
		{
			dorotate(s_a, s_b, 'r');
			p_a++;
			p_b++;
		}
	}
}

//find cheapest v to put with it's target on top of stack b
int	cheapest_b(t_node *s_a, t_node *s_b)
{
	int	cheapest_v;
	int	cheapest_cost;
	int	cost;

	cheapest_v = s_a->v;
	cheapest_cost = cost_b(s_a, s_b, cheapest_v);
	while (s_a)
	{
		cost = cost_b(s_a, s_b, s_a->v);
		if (cost < cheapest_cost)
		{
			cheapest_v = s_a->v;
			cheapest_cost = cost;
		}
		s_a = s_a->nxt;
	}
	together_to_top(&s_a, &s_b, cheapest_v, target_b(s_b, cheapest_v));
	v_to_top(&s_a, &s_b, cheapest_v, 'a');
	v_to_top(&s_a, &s_b, target_b(s_b, cheapest_v), 'b');
	dopush(&s_a, &s_b, 'b');
	return (cheapest_v);
}

//find cheapest v to put with it's target on top of stack a
int	cheapest_a(t_node *s_a, t_node *s_b)
{
	int	cheapest_v;
	int	cheapest_cost;
	int	cost;

	cheapest_v = s_b->v;
	cheapest_cost = cost_a(s_a, s_b, cheapest_v);
	while (s_b)
	{
		cost = cost_a(s_a, s_b, s_b->v);
		if (cost < cheapest_cost)
		{
			cheapest_v = s_b->v;
			cheapest_cost = cost;
		}
		s_b = s_b->nxt;
	}
	together_to_top(&s_a, &s_b, target_a(s_a, cheapest_v), cheapest_v);
	v_to_top(&s_a, &s_b, cheapest_v, 'b');
	v_to_top(&s_a, &s_b, target_a(s_a, cheapest_v), 'a');
	dopush(&s_a, &s_b, 'a');
	return (cheapest_v);
}

void	sort_turk(t_node **s_a, t_node **s_b)
{
	dopush(s_a, s_b, 'b');
	dopush(s_a, s_b, 'b');
	if ((*s_b)->v > (*s_b)->nxt->v)
		doswap(s_a, s_b, 'b');
	while (stack_len(*s_a) > 3)
		cheapest_b(*s_a, *s_b);
	sort_three(s_a);
	while (*s_b)
		cheapest_a(*s_a, *s_b);
}
