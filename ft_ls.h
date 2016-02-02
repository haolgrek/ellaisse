/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 14:59:11 by rluder            #+#    #+#             */
/*   Updated: 2016/02/02 18:45:01 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H
# include "libft/libft.h"
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <time.h>

typedef struct				s_data
{
	char					type;
	char					*file_mode;
	unsigned int			link_number;
	char					*lpath;
	char					*name;
	char					*owner;
	char					*group_name;
	unsigned int			size;
	long long				time;
	char					*ctime;
	struct s_data			*next;
}							t_data;

typedef struct				s_options
{
	int						l;
	int						R;
	int						a;
	int						r;
	int						t;
}							t_options;

#endif
