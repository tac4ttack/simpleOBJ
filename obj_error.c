/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:30:40 by fmessina          #+#    #+#             */
/*   Updated: 2019/06/17 17:24:24 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simpleOBJ.h"

bool		obj_error_log_init(void)
{
	FILE	*file;
	time_t	now;
	char	*date;

	file = fopen(SIMPLE_OBJ_ERROR_LOG_FILENAME, "w");
	if (!file)
	{
		fprintf(stderr,
				"ERROR: could not open error log file %s for writing\n",
				SIMPLE_OBJ_ERROR_LOG_FILENAME);
		return (false);
	}
	now = time(NULL);
	date = ctime(&now);
	fprintf(file, "simpleOBJ error log. Local time :%s\n", date);
	fclose(file);
	return (true);
}

bool	obj_logged_berror(const char *message, ...)
{
	FILE	*file;
	va_list	argptr;

	file = fopen(SIMPLE_OBJ_ERROR_LOG_FILENAME, "a");
	if (!file)
	{
		fprintf(stderr,
				"ERROR: could not open error log file %s for appending\n",
				SIMPLE_OBJ_ERROR_LOG_FILENAME);
		return (false);
	}
	va_start(argptr, message);
	vfprintf(file, message, argptr);
	va_end(argptr);
	va_start(argptr, message);
	vfprintf(stderr, message, argptr);
	va_end(argptr);
	fclose(file);
	return (true);
}

bool	obj_berror(const char *message, void *trash)
{
	if (trash)
	{
		(void)trash;
	}
	fprintf(stderr, "OBJ Loading error: %s\n", message);
	return (false);
}

void	*obj_error(const char *message, void *trash)
{
	if (trash)
	{
		obj_memdel((void**)(&trash));
	}
	fprintf(stderr, "OBJ Loading error: %s\n", message);
	return (NULL);
}
