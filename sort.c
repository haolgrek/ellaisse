/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 13:15:22 by rluder            #+#    #+#             */
/*   Updated: 2016/03/03 17:27:04 by rluder           ###   ########.fr       */
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
		if (data->time < data->next->time || (data->time == data->next->time && data->ntime < data->next->ntime))
		{
			tmp = swapdata(tmp, data);
			data = swapdata(data, data->next);
			data->next = swapdata(data->next, tmp);
			data = start;
		}
		else
			data = data->next;
	}
	free(tmp);
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
	free(tmp);
	return (start);
}

t_data	*rsort(t_data *data)
{
	t_data	*prev;
	t_data	*current;
	t_data	*next;

	prev = NULL;
	current = data;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return (prev);
}

t_data	*swapdata(t_data *data1, t_data *data2)
{
	data1->type = data2->type;
	data1->file_mode = data2->file_mode;
	data1->link_number = data2->link_number;
	data1->lnklen = data2->lnklen;
	data1->lpath = data1->lpath;
	data1->path = data2->path;
	data1->name = data2->name;
	data1->owner = data2->owner;
	data1->group_name = data2->group_name;
	data1->size = data2->size;
	data1->siz = data2->siz;
	data1->time = data2->time;
	data1->ctime = data2->ctime;
	data1->ntime = data2->ntime;
	data1->nblocks = data2->nblocks;
	return (data1);
}

t_data	*prep(t_data *start, t_data *data, t_options *options)
{
	data = start;
	while (start)
	{
		asciisort(start);
		start = start->next;
	}
	start = data;
	if (options->t == 1)
	{
		while (start)
		{
			tsort(start);
			start = start->next;
		}
	}
	start = data;
	if (options->r == 1)
		start = rsort(start);
	return (start);
}
