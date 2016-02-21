/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 16:01:55 by rluder            #+#    #+#             */
/*   Updated: 2016/02/21 18:44:02 by rluder           ###   ########.fr       */
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
	{
		write (1, "wut\n", 4);
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
	}
//	return (data);
	return (prep(start, data, options));
}

void	printrest(t_data *data, t_options *options)
{
	t_data	*start;

	start = data;
//	while (data && data->type != 0)
//	{
//		if (data->type != 'd')
//			printlist(data, options);
//		data = data->next;
//	}
//	data = start;
	while (data)
	{
		write (1, "wat\n", 4);
//		if (data->type == 'd')
			printlist(data, options);
		data = data->next;
	}
}
