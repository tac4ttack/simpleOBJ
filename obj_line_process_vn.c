/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_line_process_vn.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 17:53:11 by fmessina          #+#    #+#             */
/*   Updated: 2019/06/17 17:36:00 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simpleOBJ.h"

bool	obj_line_process_vn(t_obj *obj, char *str)
{
	if (obj && str)
	{
		if (!(obj_line_process_check(str, CHARSET_VN)))
			return (!obj_logged_berror("[ERROR obj_line_process_vn]\t" \
			"Wrong character found in VN line ->\t\"%s\"\n", str));
		if (!(obj_process_normal(obj, str)))
			return (!obj_logged_berror("[ERROR obj_line_process_vn]\t" \
			"Vertex normal line processing failed ->\t%s\n", str));
		return (true);
	}
	return (obj_berror("[ERROR obj_line_process_vn]\t" \
	"NULL mesh or string pointer!\n", NULL));
}
