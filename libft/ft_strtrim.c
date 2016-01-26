/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 15:40:10 by rluder            #+#    #+#             */
/*   Updated: 2015/12/03 19:13:23 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	char	*dst;
	int		start;
	int		end;
	int		i;

	start = 0;
	end = ft_strlen(s);
	i = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t' || s[end] == '\0')
		end--;
	dst = (char*)malloc(sizeof(*s) * (ft_strlen(s)));
	if (dst)
	{
		while (start <= end)
		{
			dst[i] = s[start];
			start++;
			i++;
		}
		dst[i] = '\0';
		return (dst);
	}
	return (NULL);
}
