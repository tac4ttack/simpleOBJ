/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_line_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:37:40 by fmessina          #+#    #+#             */
/*   Updated: 2019/07/01 15:47:15 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_obj.h"

static bool	obj_line_process_validate_face(t_obj *obj, char *str)
{
	size_t	len;
	char	**face_split;

	if (obj && str)
	{
		if (!(face_split = obj_strsplit(str, ' ')))
		{
			return (obj_berror("[ERROR obj_line_process_validate_face]\t"
			"Split for validating face element failed!\n", NULL));
		}
		len = obj_strsplit_len(face_split);
		obj_strsplit_destroy(face_split);
		if (len < 4 || len > 5)
			return (!(obj_log_error("[ERROR obj_line_process_validate_face]"
			"\tFace element is not a triangle or a quad! ->\t %s\n", str)));
		else if (len == 5)
			obj->n_face[0] += 2;
		else
			obj->n_face[0] += 1;
		return (true);
	}
	return (obj_berror("[ERROR obj_line_process_validate_face]\t" \
	"NULL mesh or string pointer!\n", NULL));
}

static bool	obj_line_preprocess(t_obj *obj, char **split)
{
	if (obj && split)
	{
		while (*split)
		{
			(strncmp(*split, "v ", 2) == 0 ? obj->n_vertex[0]++ : 0);
			(strncmp(*split, "vt ", 3) == 0 ? obj->n_texture[0]++ : 0);
			(strncmp(*split, "vn ", 3) == 0 ? obj->n_normal[0]++ : 0);
			(strncmp(*split, "vp ", 3) == 0 ? obj->n_space[0]++ : 0);
			if (strncmp(*split, "f ", 2) == 0)
				if (!(obj_line_process_validate_face(obj, *split)))
				{
					return (obj_berror("[ERROR obj_line_preprocess]\t" \
					"Face elements must be triangles or quads only!\n", NULL));
				}
			split++;
		}
		if (obj->n_vertex[0] < 3)
		{
			return (obj_berror("[ERROR obj_line_preprocess]\t"
			"The mesh needs at lest 3 vertices!\n", NULL));
		}
		return (true);
	}
	return (obj_berror("[ERROR obj_line_preprocess]\t" \
	"NULL mesh or split pointer!\n", NULL));
}

static bool	obj_line_process_checksum(t_obj *obj)
{
	if (obj)
	{
		fprintf(stdout, "\nMESH DATA CHECKSUM:\n"\
		"%zu vertices read\t\t\t->\t%zu vertices processed\n" \
		"%zu face(s) read\t\t\t->\t%zu face(s) processed\n" \
		"%zu normal(s) read\t\t->\t%zu normal(s) processed\n" \
		"%zu textures coords read\t\t->\t%zu textures coords processed\n" \
		"%zu vertices spaces read\t\t->\t%zu vertices spaces processed\n\n", \
		obj->n_vertex[0], obj->n_vertex[1], obj->n_face[0], \
		obj->n_face[1], obj->n_normal[0], obj->n_normal[1], \
		obj->n_texture[0], obj->n_texture[1], obj->n_space[0], \
		obj->n_space[1]);
		if (obj->n_vertex[0] != obj->n_vertex[1]
			|| obj->n_face[0] != obj->n_face[1]
			|| obj->n_normal[0] != obj->n_normal[1]
			|| obj->n_texture[0] != obj->n_texture[1]
			|| obj->n_space[0] != obj->n_space[1])
			return (obj_berror("[ERROR obj_line_process_checksum]\t" \
			"Mesh file processing failed, amount of data preprocessed" \
			" is different from amount of data processed!\n", NULL));
		return (true);
	}
	return (obj_berror("[ERROR obj_line_process_checksum]\t" \
	"NULL mesh pointer!\n", NULL));
}

static bool	obj_line_process_dispatch(t_obj *obj, char *str)
{
	bool	failure;

	if (obj && str && !(failure = false))
	{
		if (strncmp(str, "v ", 2) == 0)
			failure = obj_line_process_v(obj, str);
		else if (strncmp(str, "f ", 2) == 0)
			failure = obj_line_process_f(obj, str);
		else if (strncmp(str, "vt ", 3) == 0)
			failure = obj_line_process_vt(obj, str);
		else if (strncmp(str, "vn ", 3) == 0)
			failure = obj_line_process_vn(obj, str);
		else if (strncmp(str, "vp ", 3) == 0)
			failure = obj_line_process_vp(obj, str);
		else
			failure = true;
		return (failure);
	}
	return (!(obj_berror("[ERROR obj_line_process_dispatch]\t" \
	"NULL mesh or string pointer!\n", NULL)));
}

bool		obj_line_process(t_obj *obj, char **split)
{
	bool	failure;

	if (obj && split && !(failure = false))
	{
		fprintf(stdout, "\nMESH DATA PARSING:\n", NULL);
		if (!(obj_line_preprocess(obj, split)))
		{
			return (obj_berror("[ERROR obj_line_process]\t"
			"Mesh file pre processing failed!\n", NULL));
		}
		while (*split)
		{
			if ((failure = !obj_line_process_dispatch(obj, *split)))
			{
				return (!(obj_log_error("[ERROR obj_line_process]\t"
				"Following line is invalid! -> %s\n", *split)));
			}
			split++;
		}
		return (obj_line_process_checksum(obj));
	}
	return (obj_berror("[ERROR obj_line_process]\tNULL mesh pointer!\n", NULL));
}
