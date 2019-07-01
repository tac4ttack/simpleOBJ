/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_process_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 13:56:15 by fmessina          #+#    #+#             */
/*   Updated: 2019/07/01 16:44:42 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_obj.h"

static bool		create_vt_array(t_obj *obj)
{
	size_t		len;

	if (obj)
	{
		len = sizeof(float) * 3 * obj->n_texture[0];
		if (!(obj->texture = (float *)malloc(len)))
		{
			return (obj_berror("[ERROR create_vt_array]\t" \
			"Mesh texture UVs array memory allocation failed!\n", NULL));
		}
		memset(obj->texture, 0, len);
		return (true);
	}
	return (obj_berror("[ERROR create_vt_array]\t" \
	"NULL mesh pointer!\n", NULL));
}

static bool		obj_process_texture_validate_data(t_obj *obj, int idx, int ret)
{
	if (obj)
	{
		((ret == 2) || (ret == 1) ? obj->texture[idx + 2] = 0.0f : 0);
		(ret == 1 ? obj->texture[idx + 1] = 0.0f : 0);
		return (true);
	}
	return (obj_berror("[ERROR obj_process_texture_validate_data]\t" \
	"NULL mesh pointer!\n", NULL));
}

bool			obj_process_texture(t_obj *obj, char *str)
{
	int			i[2];

	if (obj && str)
	{
		if (!obj->texture && obj->n_texture[0] > 0)
			if (!create_vt_array(obj))
			{
				return (obj_berror("[ERROR obj_process_texture]\t" \
				"Mesh texture coordinates array creation failed!\n", NULL));
			}
		i[0] = (++obj->n_texture[1] - 1) * 3;
		i[1] = sscanf(str, "vt %f %f %f\n", &obj->texture[i[0]], \
					&obj->texture[i[0] + 1], &obj->texture[i[0] + 2]);
		if (i[1] < 1)
		{
			return (obj_berror("[ERROR obj_process_texture]\t" \
			"Texture coordinate line format is invalid!\n", NULL));
		}
		return (obj_process_texture_validate_data(obj, i[0], i[1]));
	}
	return (obj_berror("[ERROR obj_process_texture]\t" \
	"NULL mesh or string pointer!\n", NULL));
}
