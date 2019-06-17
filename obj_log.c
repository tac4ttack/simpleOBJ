/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_log.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 18:27:59 by fmessina          #+#    #+#             */
/*   Updated: 2019/06/17 18:31:55 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simpleOBJ.h"

bool		obj_log_init(void)
{
	FILE	*file;
	time_t	now;
	char	*date;

	file = fopen(SIMPLE_OBJ_LOG_FILE, "w");
	if (!file)
	{
		fprintf(stderr,
				"ERROR: could not open error log file %s for writing\n",
				SIMPLE_OBJ_LOG_FILE);
		return (false);
	}
	now = time(NULL);
	date = ctime(&now);
	fprintf(file, "simpleOBJ error log. Local time :%s\n", date);
	fclose(file);
	return (true);
}

bool	obj_log_error(const char *message, ...)
{
	FILE	*file;
	va_list	argptr;

	file = fopen(SIMPLE_OBJ_LOG_FILE, "a");
	if (!file)
	{
		fprintf(stderr,
				"ERROR: could not open error log file %s for appending\n",
				SIMPLE_OBJ_LOG_FILE);
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

bool		obj_log(const char *message, ...)
{
	FILE	*file;
	va_list	argptr;

	file = fopen(SIMPLE_OBJ_LOG_FILE, "a");
	if (!file)
	{
		fprintf(
			stderr,
			"ERROR: could not open log file %s for appending\n",
			SIMPLE_OBJ_LOG_FILE);
		return (false);
	}
	va_start(argptr, message);
	vfprintf(file, message, argptr);
	va_end(argptr);
	va_start(argptr, message);
	vprintf(message, argptr);
	va_end(argptr);
	fclose(file);
	return (true);
}

