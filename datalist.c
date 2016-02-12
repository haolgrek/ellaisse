/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datalist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 17:04:13 by rluder            #+#    #+#             */
/*   Updated: 2016/02/12 17:52:04 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

unsigned char	get_type(mode_t type)
{
	char	typ;

	typ = '\0';
	if (S_ISDIR(type))
		typ = 'd';
	else if (S_ISREG(type))
		typ = '-';
	else if (S_ISFIFO(type))
		typ = 'p';
	else if (S_ISCHR(type))
		typ = 'c';
	else if (S_ISBLK(type))
		typ = 'b';
	else if (S_ISLNK(type))
		typ = 'l';
	else if (S_ISSOCK(type))
		typ = 's';
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

t_data	*grab_all(char *argv)
{
	struct stat	buf;
	char		*bufsiz;
	t_data		*data;

	bufsiz = malloc(sizeof(char));
	data = malloc(sizeof(t_data));
	lstat(argv, &buf);
	data->type = get_type(buf.st_mode);
	data->file_mode = get_mode(buf.st_mode);
	data->link_number = buf.st_nlink;
	data->path = argv;
	data->name = cutpath(argv);
	data->owner = getpwuid(buf.st_uid)->pw_name;
	data->group_name = getgrgid(buf.st_gid)->gr_name;
	data->size = buf.st_size;
	data->time = buf.st_mtime;
	data->ctime = ctime(&(buf.st_mtime));
	readlink(argv, bufsiz, 300);
	data->lpath = bufsiz;
	data->next = (void*)0;
	return (data);
}

t_data	*get_dir(char *dirname)
{
	char			*path;
	t_data			*start;
	t_data			*data;
	DIR				*dir;
	struct dirent	*dit;

	path = ft_strjoin(dirname, "/");
	dir = opendir(dirname);
	if (!dir)
	{
		data = grab_all(dirname);
		return (data);
	}
	if ((dit = readdir(dir)))
	{
		data = grab_all(ft_strjoin(path, dit->d_name));
		start = data;
	}
	while ((dit = readdir(dir)))
	{
		data->next = grab_all(ft_strjoin(path, dit->d_name));
		data = data->next;
	}
	closedir(dir);
	return (start);
}
