/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 20:54:21 by rluder            #+#    #+#             */
/*   Updated: 2016/01/22 15:09:50 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dst;
	size_t	i;

	i = 0;
	dst = (char*)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (dst)
	{
		while (s[i] != '\0' && f)
		{
			dst[i] = f(s[i]);
			i++;
		}
		dst[i] = '\0';
		return (dst);
	}
	return (NULL);
}
