/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 19:45:38 by rluder            #+#    #+#             */
/*   Updated: 2016/01/21 20:10:36 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

/* This routine returns the size of the file it is called with. */

static unsigned	get_file_size(const char *file_name)
{
	struct stat	sb;
	if (stat(file_name, & sb) != 0)
	{
		write(1, "stat failed for ", 16);
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
	unsigned  int	size;

	i = 1;
	while (i < argc)
	{
		file_name = argv[i];
		size = get_file_size (file_name);
		ft_putstr(file_name);
		write(1, " has ", 5);
		ft_putnbr(size);
		write(1, " bytes\n", 7);
		i++;
	}
	return 0;
}
