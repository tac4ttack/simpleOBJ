/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_process_vertex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 15:58:21 by fmessina          #+#    #+#             */
/*   Updated: 2019/07/01 16:38:55 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_obj.h"

static bool		create_v_array(t_obj *obj)
{
	size_t		len;

	if (obj)
	{
		len = sizeof(float) * 8 * obj->n_vertex[0];
		if (!(obj->vertex = (float *)malloc(len)))
		{
			return (obj_berror("[ERROR create_v_array]\t" \
			"Mesh vertex array memory allocation failed!\n", NULL));
		}
		memset(obj->vertex, 0, len);
		return (true);
	}
	return (obj_berror("[ERROR create_v_array]\t" \
	"NULL mesh pointer!\n", NULL));
}

static bool		fill_vertex_hue(t_obj *obj, const int index)
{
	if (obj)
	{
		obj->vertex[index + 4] = ((float)rand() / (float)(RAND_MAX)) * 1.0f;
		obj->vertex[index + 5] = ((float)rand() / (float)(RAND_MAX)) * 1.0f;
		obj->vertex[index + 6] = ((float)rand() / (float)(RAND_MAX)) * 1.0f;
		obj->vertex[index + 7] = 1.0f;
		return (true);
	}
	return (obj_berror("[ERROR fill_vertex_hue]\tNULL mesh pointer!\n", NULL));
}

static bool		check_vertex_data(t_obj *obj, const int index, const int ret)
{
	bool		res;

	if (obj && (res = true))
	{
		if (res && ret == 3)
		{
			obj->vertex[index + 3] = 1.0f;
			res = fill_vertex_hue(obj, index);
		}
		else if (res && ret == 4)
			res = fill_vertex_hue(obj, index);
		else if (res && ret == 7)
			obj->vertex[index + 7] = 1.0f;
		else if (!res && ret != 8)
			return (obj_berror("[ERROR check_vertex_data]\tVertex line forma" \
			"t is incorrect\n It needs to be X Y Z W R G B A\nXYZ are mandato" \
			"ry, if you need color specify at least the RGB!\n", NULL));
		return (res);
	}
	return (obj_berror("[ERROR check_vertex_data]\t" \
	"NULL mesh pointer!\n", NULL));
}

bool			obj_process_vertex(t_obj *obj, char *str)
{
	int			i[2];

	if (obj && str)
	{
		if (!obj->vertex && obj->n_vertex[0] > 0)
			if (!create_v_array(obj))
				return (obj_berror("Failed create mesh vertex array!\n", NULL));
		i[0] = (++obj->n_vertex[1] - 1) * 8;
		i[1] = sscanf(str, "v %f %f %f %f %f %f %f %f\n",
					&obj->vertex[i[0]], &obj->vertex[i[0] + 1], \
					&obj->vertex[i[0] + 2], &obj->vertex[i[0] + 3], \
					&obj->vertex[i[0] + 4], &obj->vertex[i[0] + 5], \
					&obj->vertex[i[0] + 6], &obj->vertex[i[0] + 7]);
		if (i[1] < 3)
			return (obj_berror("Invalid mesh vertex line!\n", NULL));
		if (!(check_vertex_data(obj, i[0], i[1])))
			return (obj_berror("Missing values in vertex line!\n", NULL));
		return (true);
	}
	return (obj_berror("[ERROR mesh_process_vertex]\t" \
	"NULL mesh or string pointer!\n", NULL));
}
