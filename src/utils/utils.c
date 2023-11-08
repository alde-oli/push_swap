/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:48:30 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/25 11:55:47 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_create_str(void)
{
	char	*str;
	int		i;

	str = (char *) malloc(16 * sizeof(char));
	i = 0;
	while (i < 14)
	{
		str[i] = '.';
		i++;
	}
	str[0] = ' ';
	str[1] = '[';
	str[13] = ']';
	str[15] = '\0';
	return (str);
}

static int	ft_nbrlen(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len = 2;
	while (n / 10 != 0)
	{
		len += 1;
		n /= 10;
	}
	return (len);
}

void	ft_putnbr(int n)
{
	char	*dest;
	int		i;
	int		is_neg;

	is_neg = (n < 0);
	dest = ft_create_str();
	i = 12 - ((11 - ft_nbrlen(n)) / 2);
	if (n == 0)
		dest[i] = '0';
	while (n / 10 != 0 || n % 10 != 0)
	{
		if (n < 0)
			dest[i] = -1 * (n % 10) + '0';
		else
			dest[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	if (is_neg)
		dest[i] = '-';
	write(1, dest, 14);
	free(dest);
}

int	ft_atoi(char *s)
{
	int	i;
	int	v;
	int	neg;

	neg = 1;
	i = 0;
	if (s[i] == '-')
	{
		neg = -1;
		i++;
	}
	v = 0;
	while ('0' <= s[i] && s[i] <= '9')
	{
		v *= 10;
		v = v + s[i] - '0';
		i++;
	}
	v *= neg;
	return (v);
}

long long	ft_atoll(char *s)
{
	int			i;
	long long	v;
	int			neg;

	neg = 1;
	i = 0;
	if (s[i] == '-')
	{
		neg = -1;
		i++;
	}
	v = 0;
	while ('0' <= s[i] && s[i] <= '9')
	{
		v *= 10;
		v = v + s[i] - '0';
		i++;
	}
	v *= (long long)neg;
	return (v);
}
