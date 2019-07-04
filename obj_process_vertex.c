/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_process_vertex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 15:58:21 by fmessina          #+#    #+#             */
/*   Updated: 2019/07/04 16:42:13 by fmessina         ###   ########.fr       */
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

static char		*print_vertex_format(void)
{
	return ("[ERROR check_vertex_data]\tVertex line format is incorrect!\n" \
	"A vertex is created with the following formats:\n" \
	"v X Y Z W R G B A\nv X Y Z W\nv X Y Z\nv X Y Z R G B A\n" \
	"v X Y Z R G B\n With R G B A values between 0 and 1n");
}

static bool		obj_process_vertex_data(t_obj *obj, char **split, int mod[2])
{
	if (obj && split)
	{
		if (mod[1] - 1 == 3)
			return (obj_process_vertex_xyz(obj, split, mod[0]));
		else if (mod[1] - 1 == 4)
			return (obj_process_vertex_xyzw(obj, split, mod[0]));
		else if (mod[1] - 1 == 6)
			return (obj_process_vertex_xyzrgb(obj, split, mod[0]));
		else if (mod[1] - 1 == 7)
			return (obj_process_vertex_xyzrgba(obj, split, mod[0]));
		else if (mod[1] - 1 == 8)
			return (obj_process_vertex_xyzwrgba(obj, split, mod[0]));
		else
		{
			obj_strsplit_destroy(split);
			return (obj_berror("Invalid mesh vertex line!\n", NULL));
		}
	}
	return (obj_berror("[ERROR obj_process_vertex_data]\t" \
	"NULL mesh or split vertex line pointer!\n", NULL));
}

bool			obj_process_vertex(t_obj *obj, char *str)
{
	int			i[2];
	char		**split;

	if (obj && str && !(split = NULL))
	{
		if (!obj->vertex && obj->n_vertex[0] > 0)
			if (!create_v_array(obj))
				return (obj_berror("Failed create mesh vertex array!\n", NULL));
		i[0] = (++obj->n_vertex[1] - 1) * 8;
		if (!(split = obj_strsplit(str, ' ')))
			return (obj_berror("Failed to split vertex line!\n", NULL));
		i[1] = (int)obj_strsplit_len(split);
		if (i[1] != 3 && i[1] != 4 && i[1] != 6 && i[1] != 7 && i[1] != 8)
			return (obj_berror(print_vertex_format(), NULL));
		if (!(obj_process_vertex_data(obj, split, i)))
			return (obj_berror("Failed processing vertex data!\n", NULL));
		return (true);
	}
	return (obj_berror("[ERROR mesh_process_vertex]\t" \
	"NULL mesh or string pointer!\n", NULL));
}
