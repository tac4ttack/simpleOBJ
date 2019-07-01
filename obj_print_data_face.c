/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_print_data_face.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 15:09:07 by fmessina          #+#    #+#             */
/*   Updated: 2019/07/01 15:34:27 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_obj.h"

void		obj_print_data_face(t_obj *obj)
{
	size_t		i;

	if (obj && obj->face && !(i = 0))
	{
		obj_log("\nFace data =\n-----------\n", NULL);
		while (i < obj->n_face[1])
		{
			obj_log("f[%zu]\t=\t%d/%d/%d %d/%d/%d %d/%d/%d\n", i,
			obj->face[(i * 9)], \
			obj->face[(i * 9) + 1], \
			obj->face[(i * 9) + 2], \
			obj->face[(i * 9) + 3], \
			obj->face[(i * 9) + 4], \
			obj->face[(i * 9) + 5], \
			obj->face[(i * 9) + 6], \
			obj->face[(i * 9) + 7], \
			obj->face[(i * 9) + 8]);
			i++;
		}
	}
}
