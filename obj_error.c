/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:30:40 by fmessina          #+#    #+#             */
/*   Updated: 2019/07/05 11:01:10 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_obj.h"

bool	obj_face_checksum_error(const char *message)
{
	obj_log("\tFace element is not a triangle or a quad: \t %s\n", message);
	return (obj_berror("[ERROR obj_checksum_validate_face]\t"
	"Only triangles and quads are supported!\n", NULL));
}

bool	obj_berror(const char *message, void *trash)
{
	if (trash)
	{
		obj_memdel((void**)(&trash));
	}
	obj_log(message, NULL);
	fprintf(stderr, "[simpleOBJ]%s\n", message);
	return (false);
}

void	*obj_error(const char *message, void *trash)
{
	if (trash)
	{
		obj_memdel((void**)(&trash));
	}
	obj_log(message, NULL);
	fprintf(stderr, "[simpleOBJ]%s\n", message);
	return (NULL);
}
