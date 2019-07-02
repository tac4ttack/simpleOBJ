/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_process_vertex_data.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 15:34:12 by fmessina          #+#    #+#             */
/*   Updated: 2019/07/02 17:01:19 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_obj.h"

bool	obj_process_vertex_xyz(t_obj *obj, char **split, size_t i)
{
	if (obj && split)
	{
		sscanf(split[1], "%f", &obj->vertex[i + 0]);
		sscanf(split[2], "%f", &obj->vertex[i + 1]);
		sscanf(split[3], "%f", &obj->vertex[i + 2]);
		obj->vertex[i + 3] = 1.f;
		obj_strsplit_destroy(split);
		obj_hue_process(obj, i, 1);
		return (true);
	}
	return (obj_berror("[ERROR obj_process_vertex_xyz]\t" \
	"NULL mesh or split vertex line pointer!\n", NULL));
}

bool	obj_process_vertex_xyzw(t_obj *obj, char **split, size_t i)
{
	if (obj && split)
	{
		sscanf(split[1], "%f", &obj->vertex[i + 0]);
		sscanf(split[2], "%f", &obj->vertex[i + 1]);
		sscanf(split[3], "%f", &obj->vertex[i + 2]);
		sscanf(split[4], "%f", &obj->vertex[i + 3]);
		obj_strsplit_destroy(split);
		obj_hue_process(obj, i, 1);
		return (true);
	}
	return (obj_berror("[ERROR obj_process_vertex_xyzw]\t" \
	"NULL mesh or split vertex line pointer!\n", NULL));
}

bool	obj_process_vertex_xyzrgb(t_obj *obj, char **split, size_t i)
{
	if (obj && split)
	{
		sscanf(split[1], "%f", &obj->vertex[i + 0]);
		sscanf(split[2], "%f", &obj->vertex[i + 1]);
		sscanf(split[3], "%f", &obj->vertex[i + 2]);
		obj->vertex[i + 3] = 1.f;
		sscanf(split[4], "%f", &obj->vertex[i + 4]);
		sscanf(split[5], "%f", &obj->vertex[i + 5]);
		sscanf(split[6], "%f", &obj->vertex[i + 6]);
		obj->vertex[i + 7] = 1.f;
		obj_strsplit_destroy(split);
		obj_hue_process(obj, i, 1);
		return (true);
	}
	return (obj_berror("[ERROR obj_process_vertex_xyzrgb]\t" \
	"NULL mesh or split vertex line pointer!\n", NULL));
}

bool	obj_process_vertex_xyzrgba(t_obj *obj, char **split, size_t i)
{
	if (obj && split)
	{
		sscanf(split[1], "%f", &obj->vertex[i + 0]);
		sscanf(split[2], "%f", &obj->vertex[i + 1]);
		sscanf(split[3], "%f", &obj->vertex[i + 2]);
		obj->vertex[i + 3] = 1.f;
		sscanf(split[4], "%f", &obj->vertex[i + 4]);
		sscanf(split[5], "%f", &obj->vertex[i + 5]);
		sscanf(split[6], "%f", &obj->vertex[i + 6]);
		sscanf(split[7], "%f", &obj->vertex[i + 7]);
		obj_strsplit_destroy(split);
		obj_hue_process(obj, i, 1);
		return (true);
	}
	return (obj_berror("[ERROR obj_process_vertex_xyzrgba]\t" \
	"NULL mesh or split vertex line pointer!\n", NULL));
}

bool	obj_process_vertex_xyzwrgba(t_obj *obj, char **split, size_t i)
{
	if (obj && split)
	{
		sscanf(split[1], "%f", &obj->vertex[i + 0]);
		sscanf(split[2], "%f", &obj->vertex[i + 1]);
		sscanf(split[3], "%f", &obj->vertex[i + 2]);
		sscanf(split[4], "%f", &obj->vertex[i + 3]);
		sscanf(split[5], "%f", &obj->vertex[i + 4]);
		sscanf(split[6], "%f", &obj->vertex[i + 5]);
		sscanf(split[7], "%f", &obj->vertex[i + 6]);
		sscanf(split[8], "%f", &obj->vertex[i + 7]);
		obj_strsplit_destroy(split);
		obj_hue_process(obj, i, 1);
		return (true);
	}
	return (obj_berror("[ERROR obj_process_vertex_xyzwrgba]\t" \
	"NULL mesh or split vertex line pointer!\n", NULL));
}
