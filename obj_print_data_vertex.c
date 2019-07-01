/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_print_data_vertex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 15:07:38 by fmessina          #+#    #+#             */
/*   Updated: 2019/07/01 15:34:27 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_obj.h"

void		obj_print_data_vertex(t_obj *obj)
{
	size_t	i;

	if (obj && obj->vertex && !(i = 0))
	{
		obj_log("\nVertex data =\n-------------\n", NULL);
		while (i < obj->n_vertex[1])
		{
			obj_log("v[%d]\t=\t%f %f %f %f %f %f %f %f\n", i, \
					obj->vertex[(i * 8)], \
					obj->vertex[(i * 8) + 1], \
					obj->vertex[(i * 8) + 2], \
					obj->vertex[(i * 8) + 3], \
					obj->vertex[(i * 8) + 4], \
					obj->vertex[(i * 8) + 5], \
					obj->vertex[(i * 8) + 6], \
					obj->vertex[(i * 8) + 7]);
			i++;
		}
	}
}
