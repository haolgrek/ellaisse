/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 15:28:06 by rluder            #+#    #+#             */
/*   Updated: 2016/01/18 17:37:52 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	i;

	i = 0;
	if (s1 != NULL)
		i += ft_strlen(s1);
	if (s2 != NULL)
		i += ft_strlen(s2);
	dst = ft_memalloc(sizeof(char) * (i + 1));
	if (!dst)
		return (NULL);
	if (s1 != NULL)
		ft_strcpy(dst, s1);
	if (s2 != NULL)
		ft_strcat(dst, s2);
	return (dst);
}
