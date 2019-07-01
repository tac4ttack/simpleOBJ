/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_strsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 13:27:54 by fmessina          #+#    #+#             */
/*   Updated: 2019/07/01 15:34:27 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_obj.h"

char	*obj_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new;

	i = -1;
	if (s == NULL)
		return (NULL);
	if (!(new = obj_strnew(len)))
		return (NULL);
	while (++i < len)
		new[i] = s[start + i];
	new[i] = '\0';
	return (new);
}
