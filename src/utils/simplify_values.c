/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:20:43 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/31 14:03:06 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_partition(int *tab, int low, int high)
{
	int	temp;
	int	pivot;
	int	i;
	int	j;

	pivot = tab[high];
	i = (low - 1);
	j = low;
	while (j <= high - 1)
	{
		if (tab[j] < pivot)
		{
			i++;
			temp = tab[i];
			tab[i] = tab[j];
			tab[j] = temp;
		}
		j++;
	}
	temp = tab[i + 1];
	tab[i + 1] = tab[high];
	tab[high] = temp;
	return (i + 1);
}

static void	ft_quick_sort(int *tab, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = ft_partition(tab, low, high);
		ft_quick_sort(tab, low, pi - 1);
		ft_quick_sort(tab, pi + 1, high);
	}
}

static void	ft_change_values(t_node **stack, int *tab, int len)
{
	t_node	*temp;
	int		j;

	temp = *stack;
	while (temp)
	{
		j = 0;
		while (j < len)
		{
			if (temp->v == tab[j])
			{
				temp->v = j + 1;
				break ;
			}
			j++;
		}
		temp = temp->nxt;
	}
}

void	ft_simplify_stack(t_node **stack)
{
	t_node	*current;
	int		*tab;
	int		len;
	int		i;

	len = stack_len(*stack);
	tab = malloc(len * sizeof(int));
	current = *stack;
	i = 0;
	while (current)
	{
		tab[i++] = current->v;
		current = current->nxt;
	}
	ft_quick_sort(tab, 0, len - 1);
	ft_change_values(stack, tab, len);
	free(tab);
}
