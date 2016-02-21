/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 16:01:55 by rluder            #+#    #+#             */
/*   Updated: 2016/02/21 22:50:17 by rluder           ###   ########.fr       */
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
		if (lstat(argv[i], &buf) != 0)
			nofile(argv[i++]);
		else
		{
			if (!start)
			{
				data = grab_all(argv[i++]);
				start = data;
			}
			else
			{
				data->next = grab_all(argv[i++]);
				data = data->next;
			}
		}
	}
	return (prep(start, data, options));
}

void	printblocks()
{
	
}

void	printdir(t_data *data, t_options *options)
{
	t_data	*start;

	start = data;
	while (start)
	{
		if (data->name[0] != '.' || options->a == 1)
			printlist(start, options);
		start = start->next;
	}
}

void	printrest(t_data *data, t_options *options)
{
	t_data	*start;
	t_data	*temp;
	t_data	*temp2;

	temp2 = malloc(sizeof(t_data));
	start = data;
	while (data && data->type != 0)
	{
		if (data->type != 'd')
			printlist(data, options);
		data = data->next;
	}
	data = start;
	while (data)
	{
		if (data->type == 'd' && data->name[0] != '.' && ft_strcmp(data->name, ".") != 0)
		{
				ft_putchar('\n');
			ft_putstr(data->name);
			ft_putendl(":");
//			printblocks();
			ft_putendl("do as i do for data argv");
/*				if (data->name[0] != '.' && !ft_strcmp(data->name, "."))
				{
					data = get_dir(data->name);
					temp = data;
					data = data->next;
//			temp2 = temp;
					data = prep(temp, data, options);
				}
			printlist(data, options);*/
		}
		data = data->next;
	}
}
