/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_line_process_v.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:38:27 by fmessina          #+#    #+#             */
/*   Updated: 2019/07/01 15:36:15 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_obj.h"

bool	obj_line_process_v(t_obj *obj, char *str)
{
	if (obj && str)
	{
		if (!(obj_line_process_check(str, CHARSET_V)))
		{
			return (!obj_log_error("[ERROR obj_line_process_v]\t" \
			"Wrong character found in V line ->\t\"%s\"\n", str));
		}
		if (!(obj_process_vertex(obj, str)))
		{
			return (!obj_log_error("[ERROR obj_line_process_v]\t" \
			"Vertex line processing failed ->\t%s\n", str));
		}
		return (true);
	}
	return (obj_berror("[ERROR obj_line_process_v]\t" \
	"NULL mesh or string pointer!\n", NULL));
}
