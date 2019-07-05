/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_line_process_vn.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 17:53:11 by fmessina          #+#    #+#             */
/*   Updated: 2019/07/05 10:06:13 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_obj.h"

bool	obj_line_process_vn(t_obj *obj, char *str)
{
	if (obj && str)
	{
		if (!(obj_line_process_check(str, CHARSET_VN)))
		{
			obj_log("Wrong character found in VN line:\t\"%s\"\n", str);
			return (obj_berror("[ERROR obj_line_process_vn]\t" \
			"Invalid Vertex Normal element line\n", NULL));
		}
		if (!(obj_process_normal(obj, str)))
		{
			obj_log("Failed processing normal element line:\t\"%s\"\n", str);
			return (obj_berror("[ERROR obj_line_process_vn]\t" \
			"Invalid Normal element line, could not process it\n", NULL));
		}
		return (true);
	}
	return (obj_berror("[ERROR obj_line_process_vn]\t" \
	"NULL mesh or string pointer!\n", NULL));
}
