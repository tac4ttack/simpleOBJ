/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_strtrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 13:09:27 by fmessina          #+#    #+#             */
/*   Updated: 2019/07/01 15:34:27 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_obj.h"

char	*obj_strtrim(char *s)
{
	char	*dest;
	size_t	l;
	size_t	j;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	l = strlen(s);
	while ((j != l) && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
		j++;
	while ((l != j) && (s[l - 1] == ' ' || s[l - 1] == '\n'
			|| s[l - 1] == '\t'))
		l--;
	dest = obj_strnew(l - j);
	if (l > j)
	{
		while (j != l)
			dest[i++] = s[j++];
	}
	free(s);
	return (dest);
}
