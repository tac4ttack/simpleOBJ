/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_line_process_check.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 12:33:53 by fmessina          #+#    #+#             */
/*   Updated: 2019/07/01 16:26:19 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_obj.h"

bool	obj_line_process_check(char *str, char *set)
{
	if (str && set)
	{
		if ((strspn(str, set)) != strlen(str))
			return (false);
		else
			return (true);
	}
	return (obj_berror("[ERROR obj_line_process_check]\t" \
	"NULL string or charset pointer!\n", NULL));
}
