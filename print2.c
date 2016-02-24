/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 17:12:31 by rluder            #+#    #+#             */
/*   Updated: 2016/02/24 18:12:44 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_data	*getrest(int argc, char **argv, t_options *options, int i)
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
	t_data			*start;

	i = 0;
	start = data;
	if (data == NULL)
	{
		printerror(data->name);
		return ;
	}
	while (start)
	{
		start = start->next;
		i++;
	}
	if (i > 2 || options->a == 1)
	{
		if (options->l == 1)
		{
			ft_putstr("total ");
			i = countblocks(data, options);
			ft_putnbr(i);
			ft_putchar('\n');
		}
	}
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
