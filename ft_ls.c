/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 19:45:38 by rluder            #+#    #+#             */
/*   Updated: 2016/03/03 14:17:46 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_options(char **argv, int j, int i, t_options *options)
{
	if (argv[j][i] == 'l')
		options->l = 1;
	else if (argv[j][i] == 'R')
		options->rec = 1;
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
		exit(1);
	}
	options->nf = 0;
	options->dir = 0;
}

int		stock_options(char **argv, t_options *options)
{
	int			i;
	int			j;

	j = 1;
	while (argv[j] && argv[j][0] == '-' && argv[j][1])
	{
		if (argv[j][0] == '-')
		{
			i = 0;
			while (argv[j][i] != '\0')
			{
				i++;
				get_options(argv, j, i, options);
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

char	**argvpoint(int *argc)
{
	char	**argv;

	*argc = 2;
	argv = malloc(sizeof(char*) * 2);
	argv[0] = ft_strdup("ft_ls");
	argv[1] = ft_strdup(".");
	argv[2] = NULL;
	return (argv);
}

int		ispoint(char *filename)
{
	if (filename[0] == '.')
		return (1);
	return (0);
}
