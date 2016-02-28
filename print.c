/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 16:01:55 by rluder            #+#    #+#             */
/*   Updated: 2016/02/28 19:11:41 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	restdir(t_data *data, t_options *options, t_data *start, t_data *temp)
{
	while (data)
	{
		if (data->type == 'd')
		{
			if (data != start || options->nf == 1)
			{
				if (options->nf != 1)
					ft_putchar('\n');
				ft_putstr(data->name);
				ft_putendl(":");
				options->nf = 1;
			}
			temp = get_dir(data->path);
			temp = prep(temp, temp, options);
			if (temp->name[0] != '.' || (options->a == 1 ||
						!ft_strcmp(temp->name, ".")) || options->nf > 0)
				printblocks(temp, options);
			printall(temp, options);
		}
		data = data->next;
	}
}

void	printrest(t_data *data, t_options *options, char *name)
{
	t_data	*start;
	t_data	*temp;

	start = data;
	while (data)
	{
		if (data->type != 'd')
		{
			if (options->l == 1)
				printlist(data, options);
			else
				printshort(data, options);
		}
		data = data->next;
	}
	data = start;
	restdir(data, options, start, temp);
	if (temp)
		freelist(temp);
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

void	recursion(t_data *data, t_options *options)
{
	t_data	*start;
	t_data	*data2;
	int		i;

	data2 = get_dir(data->path);
	data2 = prep(data2, data2, options);
	start = data2;
	while (data2)
	{
		if (data2->type == 'd' && (data2->name[0] != '.' ||
			(ft_strcmp(data2->name, ".") && ft_strcmp(data2->name, "..")
			&& options->a == 1)))
		{
			write(1, "\n", 1);
			ft_putstr(data2->path);
			ft_putendl(":");
			if (data2->name[0] != '.' || (options->a == 1
						|| !ft_strcmp(data2->name, ".")))
				printblocks(get_dir(data2->path), options);
			i = printerror(data2);
			ft_putstr("i = ");
			ft_putnbr(i);
			ft_putchar('\n');
			if (i == 0)
			{
				start = get_dir(data2->path);
				start = prep(start, start, options);
				printall(start, options);
				recursion(data2, options);
			}
		}
		data2 = data2->next;
	}
	freelist(start);
}
