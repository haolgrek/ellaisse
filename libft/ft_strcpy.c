/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:57:21 by rluder            #+#    #+#             */
/*   Updated: 2015/12/03 19:03:17 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;
	char	*src2;
	char	*dst2;

	src2 = (char*)src;
	dst2 = (char*)dst;
	i = 0;
	while (src2[i] != '\0')
	{
		dst2[i] = src2[i];
		i++;
	}
	dst2[i] = '\0';
	return (dst);
}
