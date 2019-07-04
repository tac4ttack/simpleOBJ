/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_strsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 13:00:22 by fmessina          #+#    #+#             */
/*   Updated: 2019/07/04 16:07:42 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_obj.h"

#include <stdlib.h>

static const char	*get_next(const char *str, char c, int n)
{
	if (n)
		while (*str != '\0' && *str == c)
			str++;
	else
		while (*str != '\0' && *str != c)
			str++;
	return (str);
}

static int			compute_length(const char *str, char s)
{
	int i;

	i = 0;
	while (*str != '\0')
	{
		str = get_next(str, s, 1);
		if (*str != '\0')
		{
			i++;
			str = get_next(str, s, 0);
		}
	}
	return (i);
}

static char			**clean_failed_split(char **ret, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		free(ret[i]);
		ret[i] = NULL;
	}
	free(ret);
	ret = NULL;
	return (NULL);
}

char				**obj_strsplit(char const *str, char c)
{
	char			**ret;
	int				i;
	const char		*next;

	if (str == NULL)
		return (NULL);
	if (!(ret = (char**)malloc(sizeof(char*) * (compute_length(str, c) + 1))))
		return (NULL);
	i = 0;
	while (*str)
	{
		str = get_next(str, c, 1);
		if (*str)
		{
			next = get_next(str, c, 0);
			ret[i] = obj_strsub(str, 0, next - str);
			if (ret[i] == NULL)
				return (clean_failed_split(ret, i));
			i++;
			str = next;
		}
	}
	ret[i] = 0;
	return (ret);
}

size_t				obj_strsplit_len(char **split)
{
	size_t			ret;

	if (split)
	{
		ret = 0;
		while (*split)
		{
			ret++;
			split++;
		}
		return (ret);
	}
	return (0);
}
