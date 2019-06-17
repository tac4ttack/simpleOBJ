/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:48:48 by fmessina          #+#    #+#             */
/*   Updated: 2019/06/17 16:14:34 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simpleOBJ.h"

void		obj_strsplit_destroy(char **split)
{
	char	**tmp;

	tmp = split;
	if (*split)
	{
		while (*split)
			obj_memdel((void **)split++);
		obj_memdel((void **)(&tmp));
	}
}

void		obj_memdel(void **ptr)
{
	if (ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void		obj_clean(t_obj *mesh)
{
	if (mesh)
	{
		(mesh->object ? obj_memdel((void**)&mesh->object) : 0);
		(mesh->group ? obj_memdel((void**)&mesh->group) : 0);
		(mesh->mtllib ? obj_memdel((void**)&mesh->mtllib) : 0);
		(mesh->usemtl ? obj_memdel((void**)&mesh->usemtl) : 0);
		(mesh->prepack_vao ? obj_memdel((void **)&mesh->prepack_vao) : 0);
		(mesh->prepack_ebo ? obj_memdel((void **)&mesh->prepack_ebo) : 0);
		(mesh->vertex ? obj_memdel((void **)&mesh->vertex) : 0);
		(mesh->face ? obj_memdel((void **)&mesh->face) : 0);
		(mesh->normal ? obj_memdel((void **)&mesh->normal) : 0);
		(mesh->texture ? obj_memdel((void **)&mesh->texture) : 0);
		(mesh->space ? obj_memdel((void **)&mesh->space) : 0);
		(mesh ? obj_memdel((void **)&mesh) : 0);
	}
}
