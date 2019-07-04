/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_process_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:51:28 by fmessina          #+#    #+#             */
/*   Updated: 2019/07/04 16:22:26 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_obj.h"

static t_obj	*create_mesh(t_obj *target)
{
	if (!(target = (t_obj*)malloc(sizeof(t_obj))))
	{
		return (obj_error("[ERROR create_mesh]\t" \
		"Mesh memory allocation failed!\n", NULL));
	}
	memset(target, 0, sizeof(t_obj));
	target->object = NULL;
	target->group = NULL;
	target->mtllib = NULL;
	target->usemtl = NULL;
	target->vertex = NULL;
	target->face = NULL;
	target->normal = NULL;
	target->texture = NULL;
	target->space = NULL;
	target->axis[0].x = 0.0f;
	target->axis[0].y = 0.0f;
	target->axis[0].z = 0.0f;
	target->axis[1].x = 0.0f;
	target->axis[1].y = 0.0f;
	target->axis[1].z = 0.0f;
	return (target);
}

static void		*process_error(t_obj *obj, char **split, char *msg)
{
	if (obj)
		obj_clean(obj);
	if (split)
		obj_strsplit_destroy(split);
	return (obj_error(msg, NULL));
}

static void		obj_data_clean(char *str)
{
	int		i;

	if (str && !(i = 0))
	{
		while (str[i])
		{
			if (str[i] == '\t')
				str[i] = ' ';
			i++;
		}
	}
}

t_obj			*obj_process_file(char **data)
{
	t_obj		*obj;
	char		**split;

	if (*data)
	{
		obj_log("[simpleOBJ] Processing mesh...\n");
		obj = NULL;
		if (!(*data = obj_strtrim(*data)))
			return (obj_error("Mesh *data trimming failed!\n", *data));
		obj_data_clean(*data);
		if (!(split = obj_strsplit(*data, '\n')))
			return (obj_error("Mesh *data split failed!\n", *data));
		if (!(obj = create_mesh(obj)))
			return (process_error(obj, split, "Mesh *data creation failed!\n"));
		if (!(obj_line_process(obj, split)))
			return (process_error(obj, split, "Mesh line process failed!\n"));
		obj_strsplit_destroy(split);
		obj_memdel((void**)(data));
		if (DEBUG_OBJ)
			obj_print_data(obj);
		obj_log("[simpleOBJ] Finished processing mesh...\n");
		return (obj);
	}
	return (obj_error("[ERROR obj_process_file]\tData pointer NULL!\n", NULL));
}
