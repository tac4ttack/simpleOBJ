/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_process_face_get_type.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:59:07 by fmessina          #+#    #+#             */
/*   Updated: 2019/07/01 15:34:27 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_obj.h"

/*
**	obj_process_face_type_get():
**	Analyze the "sample" string which should be a face element definition line
**	as specified by the Wavefront OBJ mesh file format
**	Possible results are:
**	-1 = unknown
**	 0 = Vn
**	 1 = Vn/VTn
**	 2 = Vn/VTn/VNn
**	 3 = Vn//VNn
*/

int			obj_process_face_type_get(char *sample)
{
	char	**split;
	size_t	len;

	if (sample)
	{
		if (strstr(sample, "//"))
			return (3);
		else
		{
			if (!(split = obj_strsplit(sample, '/')))
				return (-1);
			len = obj_strsplit_len(split);
			obj_strsplit_destroy(split);
			if (len == 1)
				return (0);
			else if (len == 2)
				return (1);
			else if (len == 3)
				return (2);
			else
				return (-1);
		}
	}
	return (-1);
}
