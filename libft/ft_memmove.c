/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:31:33 by rluder            #+#    #+#             */
/*   Updated: 2015/12/03 19:01:07 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*src2;
	char	*dst2;
	size_t	i;

	i = 0;
	src2 = (char*)src;
	dst2 = (char*)dst;
	if (src > dst)
	{
		while (len-- > 0)
		{
			dst2[i] = src2[i];
			i++;
		}
		return (dst);
	}
	else
	{
		while (len-- > 0)
		{
			dst2[len] = src2[len];
		}
		return (dst);
	}
}
