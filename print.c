/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 16:01:55 by rluder            #+#    #+#             */
/*   Updated: 2016/02/21 17:32:07 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_data	*printnodir(int argc, char **argv, t_options *options, int i)
{
	struct stat	buf;
	t_data		*start;
	t_data		*data;

	start = NULL;
	while (i < argc)
		if (lstat(argv[i], &buf) != 0)
			nofile(argv[i++]);
		else
		{
			if (!start)
			{
				data = get_dir(argv[i++]);
				start = data;
			}
			else
			{
				data->next = get_dir(argv[i++]);
				data = data->next;
			}
		}
	return (prep(start, data, options));
}

void	printrest(t_data *data, t_options *options)
{
	t_data	*start;

	start = data;
	while (data && data->type != 0)
	{
		if (data->type != 'd')
			printlist(data, start, options);
		data = data->next;
	}
	data = start;
	while (data)
	{
		if (data->type == 'd')
			printdir(data, start, data->name);
		data = data->next;
	}
}
