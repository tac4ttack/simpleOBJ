/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_line_process_vt.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 17:12:03 by fmessina          #+#    #+#             */
/*   Updated: 2019/06/17 17:35:55 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simpleOBJ.h"

bool	obj_line_process_vt(t_obj *obj, char *str)
{
	if (obj && str)
	{
		if (!(obj_line_process_check(str, CHARSET_VT)))
			return (!obj_logged_berror("[ERROR obj_line_process_vt]\t" \
			"Wrong character found in VT line ->\t\"%s\"\n", str));
		if (!(obj_process_texture(obj, str)))
			return (!obj_logged_berror("[ERROR obj_line_process_vt]\t" \
			"Texture line processing failed ->\t%s\n", str));
		return (true);
	}
	return (obj_berror("[ERROR obj_line_process_vt]\t" \
	"NULL mesh or string pointer!\n", NULL));
}
