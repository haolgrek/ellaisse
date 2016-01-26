/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 19:45:38 by rluder            #+#    #+#             */
/*   Updated: 2016/01/26 22:09:59 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_group(char *name)
{
	struct stat		sb;
	struct group	*grp;

	if ((grp = getgrgid(sb.st_gid)) != NULL)
		return (grp->gr_name);
	else
	{
		write(1, "stat group failed for ", 22);
		ft_putstr(name);
		write(1, " : ", 3);
		ft_putstr(strerror(errno));
		write(1, ".\n", 2);
		exit (EXIT_FAILURE);
	}
}

char	*get_owner(char *name)
{
	struct stat		sb;
	struct passwd	*pwd;

	if ((pwd = getpwuid(sb.st_uid)) != NULL)
		return (pwd->pw_name);
	else
	{
		write(1, "stat owner failed for ", 22);
		ft_putstr(name);
		write(1, " : ", 3);
		ft_putstr(strerror(errno));
		write(1, ".\n", 2);
		exit (EXIT_FAILURE);
	}
}

static unsigned	get_file_size(const char *file_name)
{
	struct stat	sb;
	if (stat(file_name, & sb) != 0)
	{
		write(1, "stat size failed for ", 21);
		ft_putstr(file_name);
		write(1, " : ", 3);
		ft_putstr(strerror(errno));
		write(1, ".\n", 2);
		exit (EXIT_FAILURE);
	}
	return (sb.st_size);
}

int main (int argc, char ** argv)
{
	int				i;
	const char		*file_name;
	t_data			data;

	i = 1;
	while (i < argc)
	{
		file_name = argv[i];
		write (1, "filename : ", 11);
		data.name = (char*)file_name;
		ft_putstr(data.name);
		write (1, " owner : ", 9);
		data.owner = get_owner(data.name);
		ft_putstr(data.owner);
		write (1, " group name : ", 14);
		data.group_name = get_group(data.name);
		ft_putstr(data.group_name);
		write(1, " size : ", 9);
		data.size = get_file_size(data.name);
		ft_putnbr(data.size);
		write(1, " bytes\n", 7);
		write(1, " rights : ", 9);

		i++;
	}
	return 0;
}
