/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 16:01:55 by rluder            #+#    #+#             */
/*   Updated: 2016/03/03 17:03:40 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	printlink(t_data *data, t_options *options, t_data *temp)
{
	if (options->dir == 1)
		ft_putchar('\n');
	if (options->dir == 1 || options->dir == 2 || options->nf == 1)
	{
		ft_putstr(data->name);
		ft_putendl(":");
		}
	options->dir = 1;
	temp = get_dir(data->path);
	temp = prep(temp, temp, options);
	printall(temp, options);
}

void	restdir(t_data *data, t_options *options, t_data *temp)
{
	while (data)
	{
		if (data->type == 'd' )
		{
			if (options->dir == 1)
				ft_putchar('\n');
			if (options->dir == 1 || options->dir == 2 || options->nf == 1)
			{
				ft_putstr(data->name);
				ft_putendl(":");
			}
			options->dir = 1;
			temp = get_dir(data->path);
			temp = prep(temp, temp, options);
			printblocks(temp, options);
			printall(temp, options);
		}
		else if (data->type == 'l' && options->l == 0)
			printlink(data, options, temp);
		data = data->next;
	}
}

void	printrest(t_data *data, t_options *options)
{
	t_data	*start;
	t_data	*temp;

	start = data;
	temp = malloc(sizeof(t_data));
	while (data)
	{
		if (data->type != 'd')
		{
			if (options->l == 1)
				printlist(data, options);
			else
				printshort(data, options);
			if (options->dir == 0 || options->dir == 2)
				options->dir = 1;
		}
		data = data->next;
	}
	if (options->dir != 1 && options->dir != 3 && data != start)
		options->dir = 2;
	data = start;
	restdir(data, options, temp);
}

void	printall(t_data *start, t_options *options)
{
	while (start)
	{
		if (options->l == 1)
			printlist(start, options);
		else
			printshort(start, options);
		start = start->next;
	}
}

int		printshort(t_data *data, t_options *options)
{
	if (options->a != 1 && data->name[0] == '.')
		return (0);
	ft_putstr(data->name);
	write(1, "\n", 1);
	return (0);
}

void	printdir2(t_data *data, t_data *start)
{
	if (data != start)
		ft_putchar('\n');
	ft_putstr(data->name);
	ft_putendl(":");
}

void	recursion(t_data *data, t_options *options)
{
	t_data	*data2;
	t_data	*start;
	int		i;

	data2 = get_dir(data->path);
	data2 = prep(data2, data2, options);
	start = data2;
	printall(data2, options);
	while (data2)
	{
		options->nf = 2;
		if (data2->type == 'd' && (data2->name[0] != '.' ||
			(ft_strcmp(data2->name, ".") && ft_strcmp(data2->name, "..")
			&& options->a == 1)))
		{
			printdir2(data2, start);
			if (data2->name[0] != '.' || (options->a == 1
						|| !ft_strcmp(data2->name, ".")))
				printblocks(get_dir(data2->path), options);
			i = printerror(data2);
			if (i == 0)
				recursion(data2, options);
		}
		data2 = data2->next;
	}
}
