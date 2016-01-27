/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 16:07:25 by rluder            #+#    #+#             */
/*   Updated: 2016/01/22 15:04:01 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_size(int n)
{
	int size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	char	*dst;
	int		sign;
	int		size;

	sign = (n < 0) ? -1 : 1;
	size = ft_size(n);
	dst = malloc(sizeof(dst) * (size + 1));
	if (n == 0)
		dst[0] = '0';
	if (!dst)
		return (NULL);
	dst[size--] = '\0';
	while ((size + 1) > 0)
	{
		dst[size--] = (n % 10) * sign + 48;
		n = n / 10;
	}
	if (sign == -1)
		dst[0] = '-';
	return (dst);
}
