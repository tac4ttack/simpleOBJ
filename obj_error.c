/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:30:40 by fmessina          #+#    #+#             */
/*   Updated: 2019/06/17 20:10:39 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simpleOBJ.h"

bool	obj_berror(const char *message, void *trash)
{
	if (trash)
	{
		obj_memdel((void**)(&trash));
	}
	fprintf(stderr, "[simpleOBJ]%s\n", message);
	return (false);
}

void	*obj_error(const char *message, void *trash)
{
	if (trash)
	{
		obj_memdel((void**)(&trash));
	}
	fprintf(stderr, "[simpleOBJ]%s\n", message);
	return (NULL);
}
