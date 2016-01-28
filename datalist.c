/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datalist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 17:04:13 by rluder            #+#    #+#             */
/*   Updated: 2016/01/28 18:57:36 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_data	*ft_datanew(void const *content, size_t content_size)
{
	t_data	*datanew;

	datanew = malloc(sizeof(t_list));
	if (!datanew)
		return (NULL);
	datanew->name = NULL;
	datanew->file_mode = 0;
	datanew->link_number = 0;
	datanew->owner = NULL;
	datanew->group_name = NULL;
	datanew->size = 0;
	datanew->time = 0;
	datanew = datanew->next;
	return (datanew);
}
