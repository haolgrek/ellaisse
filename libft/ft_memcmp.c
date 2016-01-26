/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:56:31 by rluder            #+#    #+#             */
/*   Updated: 2015/11/26 15:27:11 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*buf1;
	unsigned char	*buf2;

	buf1 = (unsigned char*)s1;
	buf2 = (unsigned char*)s2;
	while (n-- > 0)
	{
		if (*buf1 == *buf2)
		{
			buf1++;
			buf2++;
		}
		else
			return (*buf1 - *buf2);
	}
	return (0);
}
