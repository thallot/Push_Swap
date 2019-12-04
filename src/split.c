/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 10:57:33 by thallot           #+#    #+#             */
/*   Updated: 2019/07/15 10:59:23 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_isword(char before, char current, char c)
{
	return ((before == c || !before) && current != c);
}

static int	ft_count(char const *s, char c)
{
	int i;
	int nb_word;

	i = 0;
	nb_word = 0;
	while (s[i])
	{
		if (i == 0)
			nb_word++;
		else if (ft_isword(s[i - 1], s[i], c))
			nb_word++;
		i++;
	}
	return (nb_word);
}

static int	ft_strlen_split(const char *s, char c)
{
	unsigned int i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char		**ft_split(char const *s, char c, int d)
{
	char	**tab;
	char	*tmp;
	int		i;
	int		j;

	tmp = (char*)s;
	i = 0;
	j = 0;
	if (!s || !(tab = (char**)malloc((ft_count(s, c) + 1) * sizeof(char*))))
		return (NULL);
	while (tmp[i])
	{
		if (i == 0)
			tab[j++] = ft_strsub(s, i, ft_strlen_split(&tmp[i], c) + d);
		else if (ft_isword(tmp[i - 1], tmp[i], c))
		{
			tab[j] = ft_strsub(s, i, ft_strlen_split(&tmp[i], c) + d);
			j++;
		}
		i++;
	}
	tab[j] = 0;
	return (tab);
}
