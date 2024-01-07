/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:51:33 by alde-oli          #+#    #+#             */
/*   Updated: 2024/01/07 17:23:53 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//nb operations to put v on top of stack
int	cost_with_r(t_node *s, int v)
{
	const int	pos = find_value(&s, &s, v, 'a');

	return (pos - 1);
}

int	cost_with_rr(t_node *s, int v)
{
	const int	len = stack_len(s);
	const int	pos = find_value(&s, &s, v, 'a');

	return (len - pos + 1);
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
		if (s->v > v && (s->v < closest || closest == -1))
			closest = s->v;
		s = s->nxt;
	}
	if (closest == -1)
		return (min);
	return (closest);
}

//nb operations to put v and it's target on top of stack b
int	cost_b(t_node *s_a, t_node *s_b, int v)
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
		return (ans[0]);
	else if (ans[1] <= ans[0] && ans[1] <= ans[2] && ans[1] <= ans[3])
		return (ans[1]);
	else if (ans[2] <= ans[0] && ans[2] <= ans[1] && ans[2] <= ans[3])
		return (ans[2]);
	else
		return (ans[3]);
}
