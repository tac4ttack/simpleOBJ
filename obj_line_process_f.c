/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_line_process_f.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 12:59:37 by fmessina          #+#    #+#             */
/*   Updated: 2019/06/17 18:30:01 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simpleOBJ.h"

bool	obj_line_process_f(t_obj *obj, char *str)
{
	if (obj && str)
	{
		if (!(obj_line_process_check(str, CHARSET_F)))
			return (!obj_log_error("[ERROR obj_line_process_f]\t" \
			"Wrong character found in F line ->\t\"%s\"\n", str));
		if (!(obj_process_face(obj, str)))
			return (!obj_log_error("[ERROR obj_line_process_f]\t" \
			"Face element line processing failed ->\t%s\n", str));
		return (true);
	}
	return (obj_berror("[ERROR obj_line_process_f]\t"\
	"NULL mesh or string pointer!\n", NULL));
}
