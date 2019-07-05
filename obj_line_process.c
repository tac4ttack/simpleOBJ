/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_line_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:37:40 by fmessina          #+#    #+#             */
/*   Updated: 2019/07/05 10:10:28 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_obj.h"

static bool	obj_line_process_dispatch(t_obj *obj, char *str)
{
	bool	failure;

	if (obj && str && !(failure = false))
	{
		if (strncmp(str, "v ", 2) == 0)
			failure = obj_line_process_v(obj, str);
		else if (strncmp(str, "f ", 2) == 0)
			failure = obj_line_process_f(obj, str);
		else if (strncmp(str, "vt ", 3) == 0)
			failure = obj_line_process_vt(obj, str);
		else if (strncmp(str, "vn ", 3) == 0)
			failure = obj_line_process_vn(obj, str);
		else if (strncmp(str, "vp ", 3) == 0)
			failure = obj_line_process_vp(obj, str);
		else
			failure = true;
		return (failure);
	}
	return (!(obj_berror("[ERROR obj_line_process_dispatch]\t" \
	"NULL mesh or string pointer!\n", NULL)));
}

bool		obj_line_process(t_obj *obj, char **split)
{
	bool	failure;

	if (obj && split && !(failure = false))
	{
		if (!(obj_checksum_preprocess(obj, split)))
		{
			return (obj_berror("[ERROR obj_line_process]\t"
			"Mesh file pre processing failed!\n", NULL));
		}
		while (*split)
		{
			if ((failure = !obj_line_process_dispatch(obj, *split)))
			{
				obj_log("Following line is invalid: %s\n", *split);
				return (obj_berror("[ERROR obj_line_process]\t" \
				"Line parsing dispatch failed", NULL));
			}
			split++;
		}
		return (obj_checksum_check(obj));
	}
	return (obj_berror("[ERROR obj_line_process]\tNULL mesh pointer!\n", NULL));
}
