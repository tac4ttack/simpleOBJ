/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_process_face_quad.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:08:01 by fmessina          #+#    #+#             */
/*   Updated: 2019/03/06 11:03:19 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simpleOBJ.h"

bool		obj_process_face_quad(t_obj *obj, char **split, int index)
{
	char	*new[2][3];

	if (obj && split)
	{
		new[0][0] = split[0];
		new[0][1] = split[1];
		new[0][2] = split[2];
		new[1][0] = split[0];
		new[1][1] = split[2];
		new[1][2] = split[3];
		if (!(obj_process_face_triangle(obj, new[0], index)))
			return (obj_berror("[ERROR obj_process_face_quad]\t" \
			"Failed to retrieve data from first new triangle!\n", NULL));
		index = (++obj->n_face[1] - 1) * 9;
		if (!(obj_process_face_triangle(obj, new[1], index)))
			return (obj_berror("[ERROR obj_process_face_quad]\t" \
			"Failed to retrieve data from second new triangle!\n", NULL));
		return (true);
	}
	return (obj_berror("[ERROR obj_process_face_quad]\t" \
	"NULL mesh or split pointer!\n", NULL));
}
