/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_print_data_texture.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:17:46 by fmessina          #+#    #+#             */
/*   Updated: 2019/06/17 18:34:37 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simpleOBJ.h"

void		obj_print_data_texture(t_obj *obj)
{
	size_t	i;

	if (obj && !(i = 0))
	{
		obj_log("\nTexture coordinates data =\n--------------------------\n");
		while (i < obj->n_texture[1])
		{
			obj_log("vt[%d]\t=\t%f %f %f\n", i, \
			obj->texture[(i * 3)], \
			obj->texture[(i * 3) + 1], \
			obj->texture[(i * 3) + 2]);
			i++;
		}
	}
}
