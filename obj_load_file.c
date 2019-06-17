/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_load_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:29:03 by fmessina          #+#    #+#             */
/*   Updated: 2019/06/17 16:43:59 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simpleOBJ.h"

static bool			obj_file_open(const char *target, size_t *size, int *fd)
{
	struct stat		file_stat;

	if ((*fd = open(target, O_RDONLY)) < 0)
	{
		return (obj_berror("[ERROR obj_file_open]\t"
			"Could not open target file!\n", NULL));
	}
	if (stat(target, &file_stat) != 0)
	{
		return (-1);
	}
	else
	{
		if (S_ISDIR(file_stat.st_mode))
		{
			return (obj_berror("[ERROR obj_get_file_size]\t" \
			"Target is a directory!\n", NULL));
		}
		else
		{
			*size = (size_t)file_stat.st_size;
			return (true);
		}
	}
}

static char			*obj_file_dump(const int fd, const size_t target_size)
{
	void			*data;
	ssize_t			read_status;

	if (fd > 0)
	{
		if (!(data = malloc(target_size + 1)))
		{
			return (obj_error("[ERROR mesh_dump_data]\t" \
			"Could not allocate memory for mesh raw data!\n", NULL));
		}
		memset(data, 0, target_size);
		if ((read_status = read(fd, data, target_size)) != (long)target_size)
		{
			return (obj_error("[ERROR obj_file_dump]\t" \
			"Mesh file read failed!\n", data));
		}
		((char *)(data))[read_status] = 0;
		close(fd);
		fprintf(stdout, "[simpleOBJ] Mesh raw data successfully read...");
		return (data);
	}
	return (obj_error("[ERROR mesh_dump_data]\t" \
	"File Descriptor is invalid!\n", NULL));
}

t_obj				*obj_load_file(char *target)
{
	t_obj			*mesh;
	size_t			len;
	int				fd;
	char			*data;

	if (target)
	{
		fprintf(stdout, "[simpleOBJ] Loading mesh...");
		if (!(obj_file_open(target, &len, &fd)))
		{
			return (obj_error("[ERROR obj_load_file]\t"
			"Could not open target file!\n", NULL));
		}
		if (!(data = obj_file_dump(fd, len)))
		{
			return (obj_error("[ERROR obj_load_file]\t" \
			"Failed dumping mesh data!\n", data));
		}
		if (!(mesh = obj_process_file(data)))
		{
			return (obj_error("[ERROR obj_load_file]\t" \
			"Failed processing mesh data!\n", data));
		}
	}
	return (obj_error("[simpleOBJ Error]\tNo target file!\n", NULL));
}
