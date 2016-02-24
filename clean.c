/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:45:24 by rluder            #+#    #+#             */
/*   Updated: 2016/02/24 18:08:28 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*cutpath(char *path)
{
	char	*filename;
	int		len;
	int		nlen;

	nlen = 0;
	len = ft_strlen(path);
	while (len && path[len] != '/')
	{
		nlen++;
		len--;
	}
	filename = malloc(sizeof(char) * (nlen + 1));
	nlen = 0;
	if (path[len] == '/')
		len++;
	while (path[len])
		filename[nlen++] = path[len++];
	filename[nlen] = '\0';
	return (filename);
}
