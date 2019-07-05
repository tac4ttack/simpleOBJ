/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_line_process_vt.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 17:12:03 by fmessina          #+#    #+#             */
/*   Updated: 2019/07/05 10:07:48 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_obj.h"

bool	obj_line_process_vt(t_obj *obj, char *str)
{
	if (obj && str)
	{
		if (!(obj_line_process_check(str, CHARSET_VT)))
		{
			obj_log("Wrong character found in VT line:\t\"%s\"\n", str);
			return (obj_berror("[ERROR obj_line_process_vt]\t" \
			"Invalid Vertex Texture element line\n", NULL));
		}
		if (!(obj_process_texture(obj, str)))
		{
			obj_log("Failed processing normal element line:\t\"%s\"\n", str);
			return (obj_berror("[ERROR obj_line_process_vt]\t" \
			"Invalid Vertex Texture element line, cannot process it\n", NULL));
		}
		return (true);
	}
	return (obj_berror("[ERROR obj_line_process_vt]\t" \
	"NULL mesh or string pointer!\n", NULL));
}
