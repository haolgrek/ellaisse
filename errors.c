/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 17:12:45 by rluder            #+#    #+#             */
/*   Updated: 2016/02/24 18:05:38 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_data	*noaccess(char *name)
{
	ft_putstr("ls: ");
	ft_putstr(name);
	ft_putendl(": Permission denied");
	return (NULL);
}

void	ebadf(char *name)
{
	ft_putstr("ls: ");
	ft_putstr(name);
	ft_putendl(": Bad file descriptor");
}

int		printerror(char *name)
{
	DIR	*dir;
	int	i;

	i = 0;
	dir = opendir(name);
	if (!dir && errno == EBADF)
		ebadf(name);
	else if (!dir)
		noaccess(name);
	if (!dir)
		i++;
	else
		closedir(dir);
	return (i);
}
