/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_strnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 13:31:17 by fmessina          #+#    #+#             */
/*   Updated: 2019/06/17 16:34:49 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simpleOBJ.h"

char		*obj_strnew(size_t size)
{
	char	*mem;

	mem = (char *)malloc(size + 1);
	if (!mem)
		return (NULL);
	memset(mem, 0, size + 1);
	return (mem);
}
