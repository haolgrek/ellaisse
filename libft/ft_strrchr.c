/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:22:06 by rluder            #+#    #+#             */
/*   Updated: 2015/11/28 18:23:02 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	d;
	char	*src;

	d = (char)c;
	src = (char*)s;
	while (*src != '\0')
		src++;
	while (*src != d && src != (char*)s)
		src--;
	if (*src == d)
		return (src);
	return (NULL);
}
