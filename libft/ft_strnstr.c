/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:07:38 by rluder            #+#    #+#             */
/*   Updated: 2015/12/04 19:23:45 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*s22;
	char	*s11;
	size_t	i;

	s22 = (char*)s2;
	s11 = (char*)s1;
	i = ft_strlen(s2);
	if (*s2 == '\0')
		return ((char*)s1);
	while (*s11 != '\0' && (n - i + 1) > 0)
	{
		if (ft_strncmp((const char*)s11, s2, i) == 0)
			return (s11);
		else
		{
			s11++;
			n--;
		}
	}
	return (NULL);
}
