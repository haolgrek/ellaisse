/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 19:45:38 by rluder            #+#    #+#             */
/*   Updated: 2016/02/21 17:32:21 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	stock_options(int argc, char **argv, t_options *options)
{
	int			i;
	int			j;

	i = 0;
	j = 1;
	options->rec = 0;
	while (argv[j] && argv[j][0] == '-')
	{
		if (argv[j][0] == '-')
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
	}
	return (j);
}

void	showlnk(t_data *data)
{
	char	buf[256];

	int		n;
	n = readlink(data->path, (char*)&buf, 255);
	write(1, buf, n);
}

int	printshort(t_data *data, t_options *options)
{
	ft_putstr(data->name);
	write(1, "\n", 1);
	return (0);
}

int	printlist(t_data *data, t_options *options)
{
	if (data->type == '0')
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
	ft_putnbr(data->size);
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

char	**argvpoint(void)
{
	char	**argv;

	argv = malloc(sizeof(char*) * 2);
	argv[0] = ft_strdup("ft_ls");
	argv[1] = ft_strdup(".");
	argv[2] = NULL;
	return (argv);
}

int	ispoint(char *filename)
{
	if (filename[0] == '.')
		return (1);
	return (0);
}

int	cleanargv(char **argv, int argc, int opt)
{
	char			*temp;
	int				i;
	struct stat		buf;
	DIR				*dir;
	struct dirent	*dit;

	i = opt;
	while ((i + 1) < argc)
	{
		if ((i + 1) < argc && ft_strcmp(argv[i], argv[i + 1]) > 0)
		{
			temp = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = temp;
			i = opt;
		}
		if ((i + 1) < argc && ft_strcmp(argv[i], argv[i + 1]) <= 0)
			i++;
	}
	i = opt;
	while ((i + 1) < argc)
	{
		if ((i + 1) < argc && lstat(argv[i], &buf) == 0 && lstat(argv[i + 1], &buf) != 0)
		{
			temp = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = temp;
			i = opt;
		}
		else
			i++;
	}
	i = opt;
	while (lstat(argv[i], &buf) != 0)
		nofile(argv[i++]);
	opt = i;
	while ((i + 1) < argc)
	{
		if ((i + 1) < argc && (dir = opendir(argv[i])) && !(dir = opendir(argv[i + 1])))
		{
			temp = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = temp;
			i = opt;
		}
		else
			i++;
	}
	return (opt);
}

int	main(int argc, char **argv)
{
	int			i;
	t_options	*options;
	t_data		*data;

	options = malloc(sizeof(t_options));
	i = stock_options(argc, argv, options);
	if (argc == i)
	{
		i = 1;
		argv = argvpoint();
	}
	i = cleanargv(argv, argc, i);
	data = printnodir(argc, argv, options, i);
	if (options->R == 1)
	{
		while (data)
		{
			if (data->type == 'd')
				recursion(data->name, options);
			data = data->next;
		}
	}
	else
		printrest(data, options);
}

/*	while (argv[i])
	{
		doall(argv[i], options);
		i++;
	}
	return (0);
}*/

/*void	doall(char *argv, t_options *options)
{
	t_data		*start;
	t_data		*larg;

	start = malloc(sizeof(t_data));
	larg = malloc(sizeof(t_data));
	larg = get_dir(argv);
	start = larg;
	larg = larg->next;
	larg = start;
	start = prep(start, larg, options);
	larg = start;
	while (larg)
	{
		if (options->R != 1)
		{
			while (start)
			{
				if (options->l == 1)
				{
					if (options->a != 1 && ispoint(start->name) == 1)
						start = start->next;
					else
					{
						printlist(start, options);
						start = start->next;
					}
				}
				else
				{
					if (options->a != 1 && ispoint(start->name) == 1)
						start = start->next;
					else
					{
						printshort(start, options);
						start = start->next;
					}
				}
			}
		}
		else
		{
			if (options->a != 1 && ispoint(start->name))
				start = start->next;
			else
			{
				recursion(start, options);
				start= start->next;
			}
		}
		larg = larg->next;
	}
}*/
