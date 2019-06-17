/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_line_process_check.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 12:33:53 by fmessina          #+#    #+#             */
/*   Updated: 2019/06/17 17:31:31 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simpleOBJ.h"

bool	obj_line_process_check(char *str, char *charset)
{
	if (str && charset)
	{
		if ((strspn(str, charset)) != strlen(str))
			return (false);
		else
			return (true);
	}
	return (obj_berror("[ERROR obj_line_process_check]\t" \
	"NULL string or charset pointer!\n", NULL));
}
