/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 17:12:31 by rluder            #+#    #+#             */
/*   Updated: 2016/03/03 17:27:33 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_data	*getrest(int argc, char **argv, t_options *options, int i)
{
	struct stat	buf;
	t_data		*start;
	t_data		*data;

	start = NULL;
	data = malloc(sizeof(t_data));
	while (i < argc)
	{
		if (lstat(argv[i], &buf) != 0)
			nofile(argv[i++], options);
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
	return (prep(start, start, options));
}

int		countblocks(t_data *data, t_options *options)
{
	int	i;

	i = 0;
	while (data)
	{
		if ((options->a == 1 && data->name[0] == '.')
				|| data->name[0] != '.')
			i = i + data->nblocks;
		data = data->next;
	}
	return (i);
}

void	printblocks(t_data *data, t_options *options)
{
	unsigned int	i;
	t_data *start;

	i = 0;
	if (data == NULL)
		return ;
	if (options->l == 1)
	{
		if (data->next->next || options->a == 1)
		{
			ft_putstr("total ");
			i = countblocks(data, options);
			ft_putnbr(i);
			ft_putchar('\n');
		}
	}
}

int		printlist(t_data *data, t_options *options)
{
	if (data->type == '0' || (options->a != 1 && data->name[0] == '.'))
		return (0);
	ft_putchar(data->type);
	ft_putstr(data->file_mode);
	write(1, " ", 1);
	ft_putnbr(data->link_number);
	write(1, " ", 1);
	ft_putstr(data->owner);
	write(1, " ", 1);
	ft_putstr(data->group_name);
	write(1, " ", 1);
	ft_putstr(data->siz);
	write(1, " ", 1);
	ft_putstr(data->ctime);
	write(1, " ", 1);
	ft_putstr(data->name);
	if (data->type == 'l')
	{
		write(1, " -> ", 4);
		showlnk(data);
	}
	write(1, "\n", 1);
	return (0);
}

void	printdir(t_data *data, t_options *options)
{
	t_data	*start;

	start = data;
	while (start)
	{
		if (data->name[0] != '.' || options->a == 1)
		{
			if (options->l == 1)
				printlist(start, options);
			else
				printshort(start, options);
		}
		start = start->next;
	}
}
