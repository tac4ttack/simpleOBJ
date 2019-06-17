/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_process_face_triangle.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:42:33 by fmessina          #+#    #+#             */
/*   Updated: 2019/06/17 17:44:12 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simpleOBJ.h"

bool		obj_process_face_triangle(t_obj *obj, char **split, int index)
{
	int		i;
	int		mod;
	bool	fail;

	if (obj && split && !(fail = false))
	{
		i = 0;
		if ((mod = obj_process_face_type_get(*split)) == -1)
			return (obj_berror("[ERROR obj_process_face_triangle]\t" \
			"Face element type recognized!\n", NULL));
		while (i++ < 3)
		{
			if (mod != obj_process_face_type_get(*split))
				return (obj_berror("[ERROR obj_process_face_triangle]\t"
				"Face element type has changed!\n", NULL));
			fail = !obj_process_face_data_dispatch(obj, *split, mod, index);
			if (fail)
				return (obj_berror("[ERROR obj_process_face_triangle]\t"
				"Failed to retrieve face element data!\n", NULL));
			index += 3;
			split++;
		}
		return (true);
	}
	return (obj_berror("[ERROR obj_process_face_triangle]\t" \
	"NULL mesh or split pointer!\n", NULL));
}
