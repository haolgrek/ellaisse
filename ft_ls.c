/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 19:45:38 by rluder            #+#    #+#             */
/*   Updated: 2016/01/28 20:00:06 by rluder           ###   ########.fr       */
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
			else if (argv[j][i] != '\0')
			{
				printf("ft_ls : illegal option -- %c\n", argv[j][i]);
				printf("usage: ft_ls [-Ralrt] [file ...]\n");
				exit (1);
			}
		}
		j++;
	}
	return (j);
}

char	get_type(mode_t type)
{
	char	typ;

	typ = (S_ISDIR(type)) ? 'd' : ' ';
	return (typ);
}

char	*get_mode(mode_t perms)
{
	char	*mode;

	mode = malloc(sizeof(char) * 10);
	mode[0] = (perms & S_IRUSR) ? 'r' : '-';
	mode[1] = (perms & S_IWUSR) ? 'w' : '-';
	mode[2] = (perms & S_IXUSR) ? 'x' : '-';
	mode[3] = (perms & S_IRGRP) ? 'r' : '-';
	mode[4] = (perms & S_IWGRP) ? 'w' : '-';
	mode[5] = (perms & S_IXGRP) ? 'x' : '-';
	mode[6] = (perms & S_IROTH) ? 'r' : '-';
	mode[7] = (perms & S_IWOTH) ? 'w' : '-';
	mode[8] = (perms & S_IXOTH) ? 'x' : '-';
	mode[9] = '\0';
	return (mode);
}

int	grab_all(int argc, char ** argv, int i)
{
	t_data			*data;
	struct stat		buf;

	data = malloc(sizeof(t_data));
	while (i < argc)
	{
		stat(argv[i], &buf);
		data->type = get_type(buf.st_mode);
		data->file_mode = get_mode(buf.st_mode);
		data->link_number = buf.st_nlink;
		data->name = argv[i];
		data->owner = getpwuid(buf.st_uid)->pw_name;
		data->group_name = getgrgid(buf.st_gid)->gr_name;
		data->size = buf.st_size;
		data->time = buf.st_mtime;
		data->next = (void*)0;
		printf("t: %c ", data->type);
		printf("m: %s ", data->file_mode);
		printf("lk: %d ", data->link_number);
		printf("nm: %s ", data->name);
		printf("ow: %s ", data->owner);
		printf("gnm: %s ", data->group_name);
		printf("sz: %dB ", data->size);
		printf("numed: %lld ", data->time);
		printf("ed: %s", ctime(&(buf.st_mtime)));
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
