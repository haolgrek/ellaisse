/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 13:15:22 by rluder            #+#    #+#             */
/*   Updated: 2016/02/16 19:55:50 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_data	*tsort(t_data *data)
{
	t_data	*start;
	t_data	*tmp;

	start = data;
	tmp = malloc(sizeof(t_data));
	while (data && data->next)
	{
		if (data->time < data->next->time)
		{
			tmp = swapdata(tmp, data);
			data = swapdata(data, data->next);
			data->next = swapdata(data->next, tmp);
			data = start;
		}
		else
			data = data->next;
	}
	return (start);
}

t_data	*asciisort(t_data *data)
{
	t_data	*start;
	t_data	*tmp;

	start = data;
	tmp = malloc(sizeof(t_data));
	while (data && data->next)
	{
		if (ft_strcmp(data->name, data->next->name) > 0)
		{
			tmp = swapdata(tmp, data);
			data = swapdata(data, data->next);
			data->next = swapdata(data->next, tmp);
			data = start;
		}
		else
			data = data->next;
	}
	return (start);
}

t_data	*rsort(t_data *data, t_data *data2)
{
	t_data	*tmp;

	if (data == NULL)
		return (data2);
	tmp = data;
	data = data->next;
	tmp->next = data2;
	return (rsort(data, tmp));
}

t_data	*swapdata(t_data *data1, t_data *data2)
{
	data1->type = data2->type;
	data1->file_mode = data2->file_mode;
	data1->link_number = data2->link_number;
	data1->path = data2->path;
	data1->name = data2->name;
	data1->owner = data2->owner;
	data1->group_name = data2->group_name;
	data1->size = data2->size;
	data1->time = data2->time;
	data1->ctime = data2->ctime;
	data1->lpath = data2->lpath;
	return (data1);
}
