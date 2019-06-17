/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_process_space.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:02:16 by fmessina          #+#    #+#             */
/*   Updated: 2019/06/17 17:57:16 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simpleOBJ.h"

static bool		create_vp_array(t_obj *obj)
{
	size_t		len;
	if (obj)
	{
		len = sizeof(float) * 3 * obj->n_space[0];
		if (!(obj->space = (float *)malloc(len)))
			return (obj_berror("[ERROR create_vp_array]\t" \
			"Mesh vertex space parameter array memory allocation failed!\n", NULL));
		memset(obj->space, 0, len);
		return (true);
	}
	return (obj_berror("[ERROR create_vp_array]\tNULL mesh pointer!\n", NULL));
}

bool			obj_process_space(t_obj *obj, char *str)
{
	size_t		i[2];

	if (obj && str)
	{
		if (!obj->space && obj->n_space > 0)
			if (!create_vp_array(obj))
				return (obj_berror("[ERROR obj_process_space]\t" \
				"Mesh vertex space parameter array creation failed!\n", NULL));
		i[0] = (++obj->n_space[1] - 1) * 3;
		i[1] = sscanf(str, "vp %f %f %f\n", &obj->space[i[0]], \
					&obj->space[i[0] + 1], &obj->space[i[0]] + 2);
		if (i[1] < 1)
			return (obj_berror("[ERROR obj_process_space]\t" \
			"Wrong vertex space paremeter definition line!\n", NULL));
		return (true);
	}
	return (obj_berror("[ERROR obj_process_space]\t" \
	"NULL mesh or string pointer!\n", NULL));
}
