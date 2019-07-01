/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_print_data_normal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 15:39:58 by fmessina          #+#    #+#             */
/*   Updated: 2019/07/01 15:39:59 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_obj.h"

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
