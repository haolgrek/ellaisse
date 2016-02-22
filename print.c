/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 16:01:55 by rluder            #+#    #+#             */
/*   Updated: 2016/02/22 17:03:34 by rluder           ###   ########.fr       */
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
		if (data->type == 'd')
		{
			if (data != start)
			{
				ft_putchar('\n');
				ft_putstr(data->name);
				ft_putendl(":");
			}
//			printblocks();
			temp = get_dir(data->name);
			temp = prep(temp, temp, options);
			while (temp)
			{
				printlist(temp, options);
				temp = temp->next;
			}
		}
		data = data->next;
	}
}

void	recursion(t_data *data, t_options *options)
{
	t_data	*start;
	t_data	*data2;

	data2 = get_dir(data->path);
	start = data2;
	data2 = prep(start, data2, options);
	start = data2;
	printdir(data2, options);
	while (data2)
	{
		if (data2->type == 'd' && (data2->name[0] != '.' || (ft_strcmp(data2->name, ".") && ft_strcmp(data2->name, "..") && options->a == 1)))
		{
			ft_putstr(data2->path);
			ft_putendl(":");
			if (data2->name[0] != '.' || options->a == 1 || !ft_strcmp(data2->name, "."))
//				printblocks();
			start = get_dir(data2->path);
			start = prep(start, start, options);
			while (start)
			{
				printlist(start, options);
				start = start->next;
			}
			recursion(data2, options);
		}
		data2 = data2->next;
	}
}
