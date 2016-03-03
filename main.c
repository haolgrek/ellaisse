/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 14:12:25 by rluder            #+#    #+#             */
/*   Updated: 2016/03/03 16:40:44 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	int			i;
	t_options	*options;
	t_data		*data;

	options = malloc(sizeof(t_options));
	i = stock_options(argv, options);
	if (argc == i)
	{
		i = 1;
		argv = argvpoint(&argc);
	}
	i = cleanargv(argv, argc, i, options);
	data = getrest(argc, argv, options, i);
	if ((argc - i) == 1)
		options->dir = 3;
	if (options->rec == 1)
	{
		while (data)
		{
			if (data->type == 'd')
			{
				if (options->nf == 2)
					write (1, "\n", 1);
				ft_putstr(data->name);
				ft_putendl(":");
				printblocks(get_dir(data->path), options);
				recursion(data, options);
			}
			data = data->next;
		}
	}
	else
		printrest(data, options);
	return (0);
}
