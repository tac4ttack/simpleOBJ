/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_line_process_vp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 17:53:11 by fmessina          #+#    #+#             */
/*   Updated: 2019/06/17 18:30:01 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simpleOBJ.h"

bool	obj_line_process_vp(t_obj *obj, char *str)
{
	if (obj && str)
	{
		if (!(obj_line_process_check(str, CHARSET_VP)))
			return (!obj_log_error("[ERROR obj_line_process_vp]\t" \
			"Wrong character found in VP line ->\t\"%s\"\n", str));
		if (!(obj_process_space(obj, str)))
			return (!obj_log_error("[ERROR obj_line_process_vp]\t" \
			"Vertex space paremeter line processing failed ->\t%s\n", str));
		return (true);
	}
	return (obj_berror("[ERROR obj_line_process_vp]\t" \
	"NULL mesh or string pointer!\n", NULL));
}
