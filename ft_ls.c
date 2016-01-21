/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 19:45:38 by rluder            #+#    #+#             */
/*   Updated: 2016/01/21 19:57:59 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

/* This routine returns the size of the file it is called with. */

static unsigned	get_file_size(const char *file_name)
{
	struct stat	sb;
	if (stat(file_name, & sb) != 0)
	{
		fprintf(stderr, "'stat' failed for '%s': %s.\n", file_name, strerror (errno));
		exit (EXIT_FAILURE);
	}
	return sb.st_size;
}

int main (int argc, char ** argv)
{
	int				i;
	const char		*file_name;
	unsigned  int	size;

	i = 0;
	while (i < argc)
	{
		file_name = argv[i];
		size = get_file_size (file_name);
		printf ("%20s has %d bytes.\n", file_name, size);
		i++;
	}
	return 0;
}
