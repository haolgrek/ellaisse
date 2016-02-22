/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 14:59:11 by rluder            #+#    #+#             */
/*   Updated: 2016/02/22 16:37:50 by rluder           ###   ########.fr       */
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
# include <dirent.h>

typedef struct				s_data
{
	unsigned char			type;
	char					*file_mode;
	unsigned int			link_number;
	int						lnklen;
	char					*lpath;
	char					*name;
	char					*path;
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
	int						rec;
}							t_options;

t_data			*get_dir(char *dirname);
t_data			*grab_all(char *argv);
char			*get_mode(mode_t perms);
unsigned char	get_type(mode_t type);
t_data			*swapdata(t_data *data1, t_data *data2);
t_data			*tsort(t_data *data);
t_data			*rsort(t_data *data);
t_data			*asciisort(t_data *data);
t_data			*prep(t_data *start, t_data *data, t_options *options);
void			nofile(char *argv);
void			recursion(t_data *data, t_options *options);
int				ispoint(char *filename);
int				printlist(t_data *data, t_options *options);
int				printshort(t_data *data, t_options *options);
t_data			*sort_argv(char *name, t_data *larg, t_data *start, t_options *options);
void			doall(char *argv, t_options *options);
t_data			*printnodir(int argc, char **argv, t_options *options, int i);
void			printrest(t_data *data, t_options *options);
#endif
