/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_process_face_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:53:33 by fmessina          #+#    #+#             */
/*   Updated: 2019/06/17 17:39:47 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simpleOBJ.h"

static bool	obj_process_face_data_v(t_obj *obj, char *str, int index)
{
	int		ret;

	if (obj && str)
	{
		ret = sscanf(str, "%d", &obj->face[index]);
		if (ret != 1)
			return (obj_berror("[ERROR obj_process_face_data_v]\t" \
			"Could not retrieve Vn face element data!\n", NULL));
		else if (obj->face[index] == 0)
			return (obj_berror("[ERROR obj_process_face_data_v]\t" \
			"Error in face element format, indices can\'t be 0!\n", NULL));
		obj->face[index + 1] = -1;
		obj->face[index + 2] = -1;
		return (true);
	}
	return (obj_berror("[ERROR obj_process_face_data_v]\t" \
	"NULL mesh or string pointer!\n", NULL));
}

static bool	obj_process_face_data_v_vt(t_obj *obj, char *str, int index)
{
	int		ret;

	if (obj && str)
	{
		ret = sscanf(str, "%d/%d", &obj->face[index], &obj->face[index + 1]);
		if (ret != 2)
			return (obj_berror("[ERROR obj_process_face_data_v_vt]\t" \
			"Could not retrieve Vn/VTn face element data!\n", NULL));
		else if (obj->face[index] == 0 || obj->face[index + 1] == 0)
			return (obj_berror("[ERROR obj_process_face_data_v_vt]\t" \
			"Error in face element format, indices can\'t be 0!\n", NULL));
		obj->face[index + 2] = -1;
		return (true);
	}
	return (obj_berror("[ERROR obj_process_face_data_v_vt]\t" \
	"NULL mesh or string pointer!\n", NULL));
}

static bool	obj_process_face_data_v_vt_vn(t_obj *obj, char *str, int index)
{
	int		ret;

	if (obj && str)
	{
		ret = sscanf(str, "%d/%d/%d", \
					&obj->face[index],
					&obj->face[index + 1],
					&obj->face[index + 2]);
		if (ret != 3)
			return (obj_berror("[ERROR obj_process_face_data_v_vt_vn]\t" \
			"Could not retrieve Vn/VTn/VNn face element data!\n", NULL));
		else if (obj->face[index] == 0 \
					|| obj->face[index + 1] == 0
					|| obj->face[index + 2] == 0)
			return (obj_berror("[ERROR obj_process_face_data_v_vt_vn]\t" \
			"Error in face element format, indices can\'t be 0!\n", NULL));
		return (true);
	}
	return (obj_berror("[ERROR obj_process_face_data_v_vt_vn]\t" \
	"NULL mesh or string pointer!\n", NULL));
}

static bool	obj_process_face_data_v_vn(t_obj *obj, char *str, int index)
{
	int		ret;

	if (obj && str)
	{
		ret = sscanf(str, "%d//%d", &obj->face[index], &obj->face[index + 2]);
		if (ret != 2)
			return (obj_berror("[ERROR obj_process_face_data_v_vn]\t" \
			"Could not retrieve Vn//VNn face element data!\n", NULL));
		else if (obj->face[index] == 0 || obj->face[index + 2] == 0)
			return (obj_berror("[ERROR obj_process_face_data_v_vn]\t" \
			"Error in face element format, indices can\'t be 0!\n", NULL));
		obj->face[index + 1] = -1;
		return (true);
	}
	return (obj_berror("[ERROR obj_process_face_data_v_vn]\t" \
	"NULL mesh or string pointer!\n", NULL));
}

bool		obj_process_face_data_dispatch(t_obj *obj, \
											char *str, \
											int mod, \
											int index)
{
	if (obj && str && mod >= 0 && mod <= 3)
	{
		if (mod == 0)
			return (obj_process_face_data_v(obj, str, index));
		else if (mod == 1)
			return (obj_process_face_data_v_vt(obj, str, index));
		else if (mod == 2)
			return (obj_process_face_data_v_vt_vn(obj, str, index));
		else if (mod == 3)
			return (obj_process_face_data_v_vn(obj, str, index));
		else
			return (false);
	}
	return (obj_berror("[ERROR obj_process_face_data_dispatch]\t" \
	"NULL mesh or string pointer, or invalid face mod!\n", NULL));
}
