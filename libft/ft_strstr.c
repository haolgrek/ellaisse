/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:03:10 by rluder            #+#    #+#             */
/*   Updated: 2015/12/03 19:12:00 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*s11;
	size_t	i;

	i = ft_strlen(s2);
	s11 = (char*)s1;
	if (*s2 == '\0')
		return ((char*)s1);
	while (*s11 != '\0')
	{
		if (ft_strncmp((const char*)s11, s2, i) == 0)
			return (s11);
		else
			s11++;
	}
	return (NULL);
}
