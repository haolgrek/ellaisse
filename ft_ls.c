/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 19:45:38 by rluder            #+#    #+#             */
/*   Updated: 2016/02/15 18:38:58 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	stock_options(int argc, char **argv, t_options *options)
{
	int			i;
	int			j;

	i = 0;
	j = argc;
	j = 1;
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

int	printshort(t_data *data, t_options *options)
{
	ft_putstr(data->name);
	write(1, "\n", 1);
	return (0);
}

int	printlist(t_data *data, t_options *options)
{
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
		ft_putstr(data->lpath);
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

int	main(int argc, char **argv)
{
	int			i;
	t_data		*start;
	t_data		*data;
	t_options	*options;

	start = malloc(sizeof(t_data));
	data = malloc(sizeof(t_data));
	options = malloc(sizeof(t_options));
	i = stock_options(argc, argv, options);
	if (argc == i)
	{
		i = 1;
		argv = argvpoint();
	}
	start = data;
	while (argv[i])
	{
		data = get_dir(argv[i]);
		start = data;
		data = data->next;
		i++;
		while (start)
		{
			asciisort(start);
			if (options->t == 1)
				tsort(start);
			if (options->l == 1)
			{
				if (options->a == 0 && ispoint(start->name) == 1)
					start = start->next;
				else
				{
					printlist(start, options);
					start = start->next;
				}
			}
			else
			{
				if (options->a == 0 && ispoint(start->name) == 1)
					start = start->next;
				else
				{
					printshort(start, options);
					start = start->next;
				}
			}
		}
	}
	return (0);
}
