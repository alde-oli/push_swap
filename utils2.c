/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:48:30 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/28 09:32:16 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_len_len(int len)
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
	while (digit > 1)
	{
		result *= 10;
		digit--;
	}
	return (result);
}