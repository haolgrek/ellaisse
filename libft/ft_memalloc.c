/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 19:49:18 by rluder            #+#    #+#             */
/*   Updated: 2016/01/22 15:06:24 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*str;

	str = (void*)malloc(sizeof(void) * size);
	if (str)
	{
		ft_bzero(str, size + 1);
		return (str);
	}
	return (NULL);
}
