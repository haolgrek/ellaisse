/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:45:24 by rluder            #+#    #+#             */
/*   Updated: 2016/02/25 14:50:01 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*cutpath(char *path)
{
	char	*filename;
	int		len;
	int		nlen;

	nlen = 0;
	len = ft_strlen(path);
	while (len && path[len] != '/')
	{
		nlen++;
		len--;
	}
	filename = malloc(sizeof(char) * (nlen + 1));
	nlen = 0;
	if (path[len] == '/')
		len++;
	while (path[len])
		filename[nlen++] = path[len++];
	filename[nlen] = '\0';
	return (filename);
}

void	alphsort(char **argv, int argc, int opt)
{
	int		i;
	char	*temp;

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
}

void	filesort(char **argv, int argc, int opt, struct stat buf)
{
	int		i;
	char	*temp;

	i = opt;
	while ((i + 1) < argc)
	{
		if ((i + 1) < argc && lstat(argv[i], &buf) == 0
				&& lstat(argv[i + 1], &buf) != 0)
		{
			temp = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = temp;
			i = opt;
		}
		else
			i++;
	}
}

void	dirsort(char **argv, int argc, int opt, struct stat buf)
{
	char			*temp;
	DIR				*dir;
	struct dirent	*dit;
	int				i;

	i = opt;
	while ((i + 1) < argc)
	{
		if ((i + 1) < argc && (dir = opendir(argv[i])) &&
				!(dir = opendir(argv[i + 1])))
		{
			temp = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = temp;
			i = opt;
		}
		else
			i++;
	}
}

int		cleanargv(char **argv, int argc, int opt, t_options *options)
{
	int				i;
	struct stat		buf;

	i = opt;
	alphsort(argv, argc, opt);
	filesort(argv, argc, opt, buf);
	while (lstat(argv[i], &buf) != 0 && i < argc)
	{
		nofile(argv[i++], options);
		opt++;
	}
	dirsort(argv, argc, opt, buf);
	return (opt);
}
