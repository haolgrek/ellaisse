/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:09:47 by rluder            #+#    #+#             */
/*   Updated: 2015/11/28 18:01:14 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	len;
	char	*s22;

	i = 0;
	s22 = (char*)s2;
	len = ft_strlen(s1);
	while (s22[i] != '\0' && i < n)
	{
		s1[len + i] = s22[i];
		i++;
	}
	s1[len + i] = '\0';
	return (s1);
}
