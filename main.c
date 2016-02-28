/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 14:12:25 by rluder            #+#    #+#             */
/*   Updated: 2016/02/28 21:26:50 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	int			i;
	t_options	*options;
	t_data		*data;

	options = malloc(sizeof(t_options));
	i = stock_options(argc, argv, options);
	if (argc == i)
	{
		i = 1;
		argv = argvpoint(&argc);
	}
	i = cleanargv(argv, argc, i, options);
	data = getrest(argc, argv, options, i);
	if (options->rec == 1)
	{
		while (data)
		{
			if (data->type == 'd')
				recursion(data, options);
			data = data->next;
		}
	}
	else
		printrest(data, options, argv[i]);
	return (0);
}
