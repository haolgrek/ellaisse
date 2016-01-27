/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 19:45:38 by rluder            #+#    #+#             */
/*   Updated: 2016/01/27 21:58:54 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	stock_options(int argc, char **argv)
{
	t_options	*options;
	int			i;
	int			j;

	i = 0;
	j = 1;
	options = malloc(sizeof(t_options));
	while (argv[j][0] == '-' && argv[j][i] != '\0')
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			i++;
			if (argv[j][i] == 'l')
				options->l = 1;
			else if (argv[j][i] == 'R')
				options->R = 1;
			else if (argv[j][i] == 'a')
				options->a = 1;
			else if (argv[j][i] == 'r')
				options->r = 1;
			else if (argv[j][i] == 't')
				options->t = 1;
			else
			{
				printf("ft_ls : illegal option -- %c\n", argv[j][i]);
				printf("usage: ft_ls [-Ralrt] [file ...]\n");
				return (0);
			}
		}
		j++;
	}
	return (j);
}

int	grab_all(int argc, char ** argv, int i)
{
//	t_data			*start;
	t_data			*data;
	struct stat		buf;

//	start = data;
	data = malloc(sizeof(t_data));
	while (i < argc)
	{
		stat(argv[i], &buf);
		data->link_number = buf.st_nlink;
		data->name = argv[i];
		data->owner = getpwuid(buf.st_uid)->pw_name;
		data->group_name = getgrgid(buf.st_gid)->gr_name;
		data->size = buf.st_size;
		data->time = buf.st_mtime;

		printf("links = %d\n", data->link_number);
		printf("name = %s\n", data->name);
		printf("owner = %s\n", data->owner);
		printf("group = %s\n", data->group_name);
		printf("size = %d Bytes\n", data->size);
		printf("last edition (num) = %lld\n", data->time);
		printf("last edition = %s\n", ctime(&(buf.st_mtime)));
//		data = data->next;
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	i = stock_options(argc, argv);
	grab_all(argc, argv, i);
}
