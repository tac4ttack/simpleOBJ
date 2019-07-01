/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_process_normal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:38:44 by fmessina          #+#    #+#             */
/*   Updated: 2019/07/01 16:41:43 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_obj.h"

static bool		create_vn_array(t_obj *obj)
{
	size_t		len;

	if (obj)
	{
		len = sizeof(float) * 3 * obj->n_normal[0];
		if (!(obj->normal = (float *)malloc(len)))
		{
			return (obj_berror("[ERROR create_vn_array]\t" \
			"Mesh normal array memory allocation failed!\n", NULL));
		}
		memset(obj->normal, 0, len);
		return (true);
	}
	return (obj_berror("[ERROR create_vn_array]\tNULL mesh pointer!\n", NULL));
}

static bool		normalize_vertex_normal(t_obj *obj, const size_t index)
{
	float	vec[4];

	if (obj)
	{
		vec[0] = obj->normal[index];
		vec[1] = obj->normal[index + 1];
		vec[2] = obj->normal[index + 2];
		vec[3] = sqrt((vec[0] * vec[0]) \
					+ (vec[1] * vec[1]) \
					+ (vec[2] * vec[2]));
		obj->normal[index] = vec[0] / vec[3];
		obj->normal[index + 1] = vec[1] / vec[3];
		obj->normal[index + 2] = vec[2] / vec[3];
		return (true);
	}
	return (obj_berror("[ERROR normalize_vertex_normal]\t" \
	"NULL mesh pointer!\n", NULL));
}

bool			obj_process_normal(t_obj *obj, char *str)
{
	size_t		i[2];

	if (obj && str)
	{
		if (!obj->normal && obj->n_normal > 0)
			if (!create_vn_array(obj))
				return (obj_berror("Failed create mesh normal array!\n", NULL));
		i[0] = (++obj->n_normal[1] - 1) * 3;
		i[1] = sscanf(str, "vn %f %f %f\n", &obj->normal[i[0]], \
					&obj->normal[i[0] + 1], &obj->normal[i[0]] + 2);
		if (i[1] != 3)
			return (obj_berror("Invalid vertex normal line!\n", NULL));
		if (!normalize_vertex_normal(obj, i[0]))
			return (obj_berror("Failed normalize mesh normal!\n", NULL));
		return (true);
	}
	return (obj_berror("[ERROR obj_process_normal]\t" \
	"NULL mesh or string pointer!\n", NULL));
}
