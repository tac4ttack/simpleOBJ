/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_process_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:51:28 by fmessina          #+#    #+#             */
/*   Updated: 2019/06/17 17:25:10 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simpleOBJ.h"

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
	target->prepack_vao = NULL;
	target->prepack_ebo = NULL;
	target->vertex = NULL;
	target->face = NULL;
	target->normal = NULL;
	target->texture = NULL;
	target->space = NULL;
	return (target);
}

static void		*obj_processing_error(t_obj *obj, char **split, char *msg)
{
	if (obj)
	{
		obj_clean(obj);
	}
	if (split)
	{
		obj_strsplit_destroy(split);
	}
	return (obj_error(msg, NULL));
}

t_obj			*obj_process_file(char *data)
{
	t_obj		*obj;
	char		**split;

	if (data)
	{
		fprintf(stdout, "[simpleOBJ] Processing mesh...");
		assert(obj_error_log_init());
		if (!(data = obj_strtrim(data)))
			return (obj_error("[ERROR obj_file_process]\t" \
					"Mesh data trimming failed!\n", data));
			if (!(split = obj_strsplit(data, '\n')))
			return (obj_error("[ERROR obj_file_process]\t" \
					"Mesh data split failed!\n", data));
			if (!(obj = create_mesh(obj)))
			return (obj_processing_error(obj, split, \
					"[ERROR obj_file_process]\tMesh data creation failed!\n"));
			if (!(obj_line_process(obj, split)))
			return (obj_file_processing_error(obj, split, \
			"[ERROR obj_file_process]\tMesh line processing failed!\n"));
			obj_strsplit_destroy(split);
		fprintf(stdout, "[simpleOBJ] Finished processing mesh...");
		return (obj);
	}
	return (obj_error("[ERROR obj_process_file]\tData pointer NULL!\n", NULL));
}
