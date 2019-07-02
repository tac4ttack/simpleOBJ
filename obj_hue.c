/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_hue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:34:46 by fmessina          #+#    #+#             */
/*   Updated: 2019/07/02 16:59:58 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_obj.h"

static float	obj_hue_correct(const float val)
{
	float		res;

	res = (val < 0.f ? (val * -1.f) : val);
	res = (res > 1.f ? (res / 255.f) : res);
	return (res);
}

bool			obj_hue_process(t_obj *obj, const int i, const int mod)
{
	if (obj)
	{
		if (mod == 0)
		{
			obj->vertex[i + 4] = ((float)rand() / (float)(RAND_MAX)) * 1.0f;
			obj->vertex[i + 5] = ((float)rand() / (float)(RAND_MAX)) * 1.0f;
			obj->vertex[i + 6] = ((float)rand() / (float)(RAND_MAX)) * 1.0f;
			obj->vertex[i + 7] = 1.0f;
		}
		else if (mod == 1)
		{
			obj->vertex[i + 4] = obj_hue_correct(obj->vertex[i + 4]);
			obj->vertex[i + 5] = obj_hue_correct(obj->vertex[i + 5]);
			obj->vertex[i + 6] = obj_hue_correct(obj->vertex[i + 6]);
			obj->vertex[i + 7] = obj_hue_correct(obj->vertex[i + 7]);
		}
		return (true);
	}
	return (obj_berror("[ERROR obj_hue_process]\tNULL mesh pointer!\n", NULL));
}
