/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:36:18 by alde-oli          #+#    #+#             */
/*   Updated: 2024/01/04 09:25:58 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	find_max(t_node *s)
{
	int	max;

	max = s->v;
	while (s)
	{
		if (s->v > max)
			max = s->v;
		s = s->nxt;
	}
	return (max);
}

int	find_min(t_node *s)
{
	int	min;

	min = s->v;
	while (s)
	{
		if (s->v < min)
			min = s->v;
		s = s->nxt;
	}
	return (min);
}

void	ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (len--)
		*(ptr++) = (unsigned char)c;
}
