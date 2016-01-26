/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 16:59:08 by rluder            #+#    #+#             */
/*   Updated: 2015/12/08 15:11:23 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_countwords(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (*s)
	{
		if (word == 0 && *s != c)
		{
			word = 1;
			i++;
		}
		else if (word == 1 && *s == c)
			word = 0;
		s++;
	}
	return (i);
}

static int	ft_wordsize(char const *s, char c)
{
	int	size;

	size = 0;
	while (*s != '\0' && *s != c)
	{
		size++;
		s++;
	}
	return (size);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		index;
	int		nbrwords;

	if (s && c)
	{
		index = 0;
		nbrwords = ft_countwords(s, c);
		tab = malloc(sizeof(char*) * (nbrwords + 1));
		if (!tab)
			return (NULL);
		while (nbrwords--)
		{
			while (*s == c)
				s++;
			tab[index] = ft_strsub(s, 0, ft_wordsize(s, c));
			if (tab[index] == NULL)
				return (NULL);
			s = s + ft_wordsize(s, c);
			index++;
		}
		tab[index] = NULL;
		return (tab);
	}
	return (NULL);
}
