/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:04:43 by rluder            #+#    #+#             */
/*   Updated: 2015/12/04 19:42:09 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	max;

	i = 0;
	while (dst[i] != '\0' && i < size)
		i++;
	max = i;
	while (src[i - max] && i < size - 1)
	{
		dst[i] = src[i - max];
		i++;
	}
	if (max < size)
		dst[i] = '\0';
	return (max + ft_strlen(src));
}
