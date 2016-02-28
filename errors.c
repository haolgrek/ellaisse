/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 17:12:45 by rluder            #+#    #+#             */
/*   Updated: 2016/02/28 18:26:15 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_data	*noaccess(t_data *data)
{
	ft_putstr("ls: ");
	ft_putstr(data->name);
	ft_putendl(": Permission denied");
	return (NULL);
}

void	ebadf(t_data *data)
{
	ft_putstr("ls: ");
	ft_putstr(data->name);
	ft_putendl(": Bad file descriptor");
}

int		printerror(t_data *data)
{
	DIR	*dir;
	int	i;

	i = 0;
	dir = opendir(data->path);
	if (!dir && errno == EBADF)
	{
		ebadf(data);
		i++;
	}
	else if (!dir)
	{
		noaccess(data);
		i++;
	}
	if (!dir)
		i++;
	else
		closedir(dir);
	return (i);
}
