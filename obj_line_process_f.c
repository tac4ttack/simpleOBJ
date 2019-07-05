/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_line_process_f.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 12:59:37 by fmessina          #+#    #+#             */
/*   Updated: 2019/07/05 09:50:23 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_obj.h"

bool	obj_line_process_f(t_obj *obj, char *str)
{
	if (obj && str)
	{
		if (!(obj_line_process_check(str, CHARSET_F)))
		{
			obj_log("Wrong character found in F line:\t\"%s\"\n", str);
			return (obj_berror("[ERROR obj_line_process_f]\t" \
			"Invalid Face element line\n", NULL));
		}
		if (!(obj_process_face(obj, str)))
		{
			obj_log("Failed processing face element line:\t\"%s\"\n", str);
			return (obj_berror("[ERROR obj_line_process_f]\t" \
			"Invalid Face element line, could not process it\n", NULL));
		}
		return (true);
	}
	return (obj_berror("[ERROR obj_line_process_f]\t"\
	"NULL mesh or string pointer!\n", NULL));
}
