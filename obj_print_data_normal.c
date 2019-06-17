/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_print_data_normal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:38:08 by fmessina          #+#    #+#             */
/*   Updated: 2019/03/06 14:45:13 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simpleOBJ.h"

void		obj_print_data_normal(t_obj *obj)
{
	size_t	i;

	if (obj && !(i = 0))
	{
		obj_log("\nVertices normals data =\n------------------------\n");
		while (i < obj->n_normal[1])
		{
			obj_log("vn[%d]\t=\t%f %f %f\n", i, \
			obj->normal[(i * 3)], \
			obj->normal[(i * 3) + 1], \
			obj->normal[(i * 3) + 2]);
			i++;
		}
	}
}
