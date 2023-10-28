/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:48:30 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/28 23:05:37 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t len, size_t size)
{
	void	*s;

	s = malloc(size * len);
	if (!s)
		return (NULL);
	while (len * size > 0)
	{
		((char *)s)[len * size - 1] = 0;
		len--;
	}
	return (s);
}

static int	ft_strnbr(char const *s, char c)
{
	int	s_nbr;
	int	i;

	s_nbr = 0;
	i = 0;
	if (s[i] != c)
		s_nbr++;
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			s_nbr++;
		i++;
	}
	return (s_nbr);
}

static char	*ft_strcdup(char const *src, int *i, char c)
{
	int		j;
	char	*dest;

	j = 0;
	while (src[*i + j] && src[*i + j] != c)
		j++;
	dest = ft_calloc((j + 1), sizeof(char));
	if (!dest)
		return (NULL);
	j = 0;
	while (src[*i] && src[*i] != c)
	{
		dest[j] = src[*i];
		j++;
		(*i)++;
	}
	return (dest);
}

void	ft_dest_clear(char **dest, int j)
{
	if (!dest[j])
	{
		while (j >= 0)
		{
			free(dest[j]);
			j--;
		}
		free(dest);
	}
}

char	**ft_split(char const *s)
{
	char	**dest;
	int		s_nbr;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	s_nbr = ft_strnbr(s, ' ');
	dest = ft_calloc((s_nbr + 1), sizeof(char *));
	if (!dest)
		return (NULL);
	while (j < s_nbr)
	{
		while (s[i] && s[i] == ' ')
			i++;
		if (!s[i])
			break ;
		dest[j] = ft_strcdup(s, &i, ' ');
		ft_dest_clear(dest, j);
		j++;
	}
	dest[j] = NULL;
	return (dest);
}
