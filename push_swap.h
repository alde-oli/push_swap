/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:32:23 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/21 17:24:22 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_node{
	int				v;
	struct s_node	*next;
}	t_node;

//operations
void	ft_swap(t_node **stack);
void	ft_push(t_node **src, t_node **dest);
void	ft_rotate(t_node **stack);
void	ft_reverse_rotate(t_node **stack);

#endif