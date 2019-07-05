/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_line_process_vp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 17:53:11 by fmessina          #+#    #+#             */
/*   Updated: 2019/07/05 11:09:33 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_obj.h"

bool	obj_line_process_vp(t_obj *obj, char *str)
{
	if (obj && str)
	{
		if (!(obj_line_process_check(str, CHARSET_VP)))
		{
			obj_log("[ERROR obj_line_process_vp]\t" \
			"Wrong character found in VP line:\t\"%s\"\n", str);
			return (obj_berror("[ERROR obj_line_process_vp]\t" \
			"Invalid Vertex Space element line\n", NULL));
		}
		if (!(obj_process_space(obj, str)))
		{
			obj_log("[ERROR obj_line_process_vp]\t" \
			"Failed processing normal element line:\t\"%s\"\n", str);
			return (obj_berror("[ERROR obj_line_process_vp]\t" \
			"Invalid Vertex Space element line, could not process it\n", NULL));
		}
		return (true);
	}
	return (obj_berror("[ERROR obj_line_process_vp]\t" \
	"NULL mesh or string pointer!\n", NULL));
}
