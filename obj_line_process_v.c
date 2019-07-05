/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_line_process_v.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:38:27 by fmessina          #+#    #+#             */
/*   Updated: 2019/07/05 10:04:25 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_obj.h"

bool	obj_line_process_v(t_obj *obj, char *str)
{
	if (obj && str)
	{
		if (!(obj_line_process_check(str, CHARSET_V)))
		{
			obj_log("Wrong character found in V line:\t\"%s\"\n", str);
			return (obj_berror("[ERROR obj_line_process_v]\t" \
			"Invalid Vertex element line\n", NULL));
		}
		if (!(obj_process_vertex(obj, str)))
		{
			obj_log("Failed processing vertex element line:\t\"%s\"\n", str);
			return (obj_berror("[ERROR obj_line_process_v]\t" \
			"Invalid Vertex element line, could not process it\n", NULL));
		}
		return (true);
	}
	return (obj_berror("[ERROR obj_line_process_v]\t" \
	"NULL mesh or string pointer!\n", NULL));
}
