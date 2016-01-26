/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 13:00:37 by rluder            #+#    #+#             */
/*   Updated: 2016/01/18 16:57:26 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s1, size_t n)
{
	char	*s2;
	char	*tmp;
	size_t	size;

	size = (n < ft_strlen(s1) + 1) ? n : ft_strlen(s1);
	if ((s2 = ft_memalloc(size + 1)) == NULL)
		return (NULL);
	tmp = s2;
	while (*s1 != '\0' && n > 0)
	{
		*s2++ = *s1++;
		n--;
	}
	*s2 = '\0';
	return (tmp);
}
