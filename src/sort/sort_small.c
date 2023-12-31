/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:32:44 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/31 14:44:22 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **s)
{
	if (is_sorted(*s))
		return ;
	if ((*s)->v < (*s)->nxt->nxt->v && (*s)->nxt->nxt->v < (*s)->nxt->v)
	{
		dorevrotate(s, NULL, 'a');
		doswap(s, NULL, 'a');
	}
	else if ((*s)->nxt->v < (*s)->v
		&& (*s)->v < (*s)->nxt->nxt->v)
		doswap(s, NULL, 'a');
	else if ((*s)->nxt->v < (*s)->nxt->nxt->v && (*s)->nxt->nxt->v < (*s)->v)
		dorotate(s, NULL, 'a');
	else if ((*s)->nxt->nxt->v < (*s)->v && (*s)->v < (*s)->nxt->v)
		dorevrotate(s, NULL, 'a');
	else if ((*s)->nxt->nxt->v < (*s)->nxt->v && (*s)->nxt->v < (*s)->v)
	{
		dorotate(s, NULL, 'a');
		doswap(s, NULL, 'a');
	}
}

void	sort_four(t_node **s_a, t_node **s_b)
{
	if ((*s_a)->v == 2 && (*s_a)->nxt->v == 1)
		doswap(s_a, s_b, 'a');
	else
		v_to_top(s_a, s_b, 1, 'a');
	if (is_sorted(*s_a))
		return ;
	dopush(s_a, s_b, 'b');
	sort_three(s_a);
	dopush(s_a, s_b, 'a');
}

void	sort_five(t_node **s_a, t_node **s_b)
{
	v_to_top(s_a, s_b, 1, 'a');
	if (is_sorted(*s_a))
		return ;
	dopush(s_a, s_b, 'b');
	if ((*s_a)->v == 3 && (*s_a)->nxt->v == 2)
		doswap(s_a, s_b, 'a');
	else
		v_to_top(s_a, s_b, 2, 'a');
	if (is_sorted(*s_a))
	{
		dopush(s_a, s_b, 'a');
		return ;
	}
	dopush(s_a, s_b, 'b');
	sort_three(s_a);
	dopush(s_a, s_b, 'a');
	dopush(s_a, s_b, 'a');
}
