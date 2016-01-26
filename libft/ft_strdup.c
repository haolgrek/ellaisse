/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:16:02 by rluder            #+#    #+#             */
/*   Updated: 2015/12/04 19:46:28 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*s2;

	if ((s2 = (char*)malloc(sizeof(*s1) * (ft_strlen(s1) + 1))))
		return (ft_strcpy(s2, s1));
	return (NULL);
}
