/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_checksum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 12:49:50 by fmessina          #+#    #+#             */
/*   Updated: 2019/07/05 11:00:29 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_obj.h"

static void		obj_checksum_print(t_obj *obj)
{
	if (obj)
	{
		obj_log("\nMESH DATA CHECKSUM:\n"\
		"%zu vertices read\t\t\t->\t%zu vertices processed\n" \
		"%zu face(s) read\t\t\t->\t%zu face(s) processed\n" \
		"%zu normal(s) read\t\t->\t%zu normal(s) processed\n" \
		"%zu textures coords read\t\t->\t%zu textures coords processed\n" \
		"%zu vertices spaces read\t\t->\t%zu vertices spaces processed\n\n", \
		obj->n_vertex[0], obj->n_vertex[1], obj->n_face[0], \
		obj->n_face[1], obj->n_normal[0], obj->n_normal[1], \
		obj->n_texture[0], obj->n_texture[1], obj->n_space[0], \
		obj->n_space[1]);
	}
}

static void		obj_checksum_preprocess_print(t_obj *obj)
{
	if (obj)
	{
		obj_log("\nMESH DATA PARSING:\nPreprocessing:\n%zu " \
		"Vertices\n%zu Polygons\n%zu Vertex texture coordinates\n" \
		"%zu Vertex normals\n%zu Space vertices\n", \
		obj->n_vertex[0], obj->n_face[0], obj->n_texture[0], \
		obj->n_normal[0], obj->n_space[0]);
	}
}

static bool		obj_checksum_validate_face(t_obj *obj, char *str)
{
	size_t		len;
	char		**face_split;

	if (obj && str)
	{
		if (!(face_split = obj_strsplit(str, ' ')))
		{
			return (obj_berror("[ERROR obj_checksum_validate_face]\t"
			"Split for validating face element failed!\n", NULL));
		}
		len = obj_strsplit_len(face_split);
		obj_strsplit_destroy(face_split);
		if (len < 4 || len > 5)
			obj_face_checksum_error(str);
		else if (len == 5)
			obj->n_face[0] += 2;
		else
			obj->n_face[0] += 1;
		return (true);
	}
	return (obj_berror("[ERROR obj_checksum_validate_face]\t" \
	"NULL mesh or string pointer!\n", NULL));
}

bool			obj_checksum_check(t_obj *obj)
{
	if (obj)
	{
		obj_checksum_print(obj);
		if (obj->n_vertex[0] != obj->n_vertex[1]
			|| obj->n_face[0] != obj->n_face[1]
			|| obj->n_normal[0] != obj->n_normal[1]
			|| obj->n_texture[0] != obj->n_texture[1]
			|| obj->n_space[0] != obj->n_space[1])
			return (obj_berror("[ERROR obj_checksum_check]\t" \
			"Mesh file processing failed, amount of data preprocessed" \
			" is different from amount of data processed!\n", NULL));
		return (true);
	}
	return (obj_berror("[ERROR obj_checksum_check]\t" \
	"NULL mesh pointer!\n", NULL));
}

bool			obj_checksum_preprocess(t_obj *obj, char **split)
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
				if (!(obj_checksum_validate_face(obj, *split)))
				{
					return (false);
				}
			split++;
		}
		if (obj->n_vertex[0] < 3)
		{
			return (obj_berror("[ERROR obj_checksum_preprocess]\t"
			"The mesh needs at lest 3 vertices!\n", NULL));
		}
		obj_checksum_preprocess_print(obj);
		return (true);
	}
	return (obj_berror("[ERROR obj_checksum_preprocess]\t" \
	"NULL mesh or split pointer!\n", NULL));
}
