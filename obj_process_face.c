/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_process_face.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 12:59:37 by fmessina          #+#    #+#             */
/*   Updated: 2019/07/01 16:37:26 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_obj.h"

static bool		create_face_array(t_obj *obj)
{
	size_t		len;

	if (obj)
	{
		len = sizeof(int) * obj->n_face[0] * 9;
		if (!(obj->face = (int *)malloc(len)))
		{
			return (obj_berror("[ERROR create_face_array]\t"
			"Mesh face array memory allocation failed!\n", NULL));
		}
		memset(obj->face, 0, len);
		return (true);
	}
	return (obj_berror("[ERROR create_f_array]\tNULL mesh pointer!\n", NULL));
}

bool			obj_process_face(t_obj *obj, char *str)
{
	int			i[2];
	char		**split;

	if (obj && str && !(i[1] = 0))
	{
		if (!obj->face && obj->n_face[0] > 0)
			if (!create_face_array(obj))
				return (obj_berror("Failed create mesh face array!", NULL));
		i[0] = (++obj->n_face[1] - 1) * 9;
		if (!(split = obj_strsplit(str, ' ')))
			return (obj_berror("Invalid mesh face line format!\n", NULL));
		if (obj_strsplit_len(split) == 5)
			i[1] = !obj_process_face_quad(obj, split + 1, i[0]);
		else
			i[1] = !obj_process_face_triangle(obj, split + 1, i[0]);
		obj_strsplit_destroy(split);
		if (i[1])
		{
			return (obj_berror("Failed to process face line!\n", NULL));
		}
		return (true);
	}
	return (obj_berror("[ERROR obj_process_face]\t" \
	"NULL mesh or line pointer!\n", NULL));
}
