/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_print_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:36:33 by fmessina          #+#    #+#             */
/*   Updated: 2019/07/01 15:36:24 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_obj.h"

void	obj_print_data(t_obj *obj)
{
	if (obj->vertex)
		obj_print_data_vertex(obj);
	if (obj->normal)
		obj_print_data_normal(obj);
	if (obj->texture)
		obj_print_data_texture(obj);
	if (obj->face)
		obj_print_data_face(obj);
	obj_log("\n\n", NULL);
}
