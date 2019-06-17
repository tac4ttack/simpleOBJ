/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simpleOBJ.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:17:24 by fmessina          #+#    #+#             */
/*   Updated: 2019/06/17 17:25:19 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMPLE_OBJ_PARSER_H
# define SIMPLE_OBJ_PARSER_H

# include <stdbool.h>	// required for bool type
# include <fcntl.h>		// required for open()
# include <unistd.h>	// required for read() and close()
# include <stdio.h>		// required for FILE printf etc
# include <sys/stat.h>	// required for stat()
# include <stdlib.h>
# include <string.h>

# define SIMPLE_OBJ_ERROR_LOG_FILENAME "simpleOBJ_error.log"

typedef struct	s_vec3f
{
	float			x;
	float			y;
	float			z;
}					t_vec3f;

/*
**	MESH DATA STRUCT:
**	-----------------
**	object		->	object name
**	group		->	object's group name
**	mtllib		->	mtllib specified file
**	usemtl		->	material file specified
**	shading		->	s line boolean
**	vertex		->	vertices array, defined with 4 components
**	n_vertex	->	number of vertices, [0] is preprocessing count,
**					[1] is for checksum and filling
**	face		->	face elements array
**	n_face		->	face elements settings:
**					[0] preprocessing count,
**					[1] checksum control,
**	normal		->	vertices normal array
**	n_normal	->	number of vertices normals:
**					[0] is preprocessing count,
**					[1] is for checksum and filling
**	texture		->	vertices texture coord array
**	n_texture	->	number of vertices texture coord:
**					[0] is preprocessing count,
**					[1] is for checksum and filling
**	space		->	space vertices array
**	n_space		->	number of space vertices:
**					[0] is preprocessing count,
**					[1] is for checksum and filling
**	linel		->	polyline definition array
**	n_line		->	number of polylines:
**					[0] is preprocessing count,
**					[1] is for checksum and filling
*/
typedef struct					s_obj
{
	char						*object;
	char						*group;
	char						*mtllib;
	char						*usemtl;
	bool						shading;

	float						*prepack_vao;
	unsigned int				*prepack_ebo;

	float						*vertex;
	size_t						n_vertex[2];

	unsigned int				*face;
	size_t						n_face[2];

	float						*normal;
	size_t						n_normal[2];

	float						*texture;
	size_t						n_texture[2];

	float						*space;
	size_t						n_space[2];

	t_vec3f						axis[3];	//DO THE AXIS CENTERING
}								t_obj;


/*
**	simpleOBJ parser core functions
*/
t_obj						*obj_load_file(char *target);
t_obj						*obj_process_file(char *data);

/*
**	Error handling functions
*/
void							*obj_error(const char *message, void *trash);
bool							obj_berror(const char *message, void *trash);
bool							obj_error_log_init(void);
bool							obj_logged_berror(const char *message, ...);

/*
**	Memory management functions
*/
void							obj_clean(t_obj *mesh);
void							obj_memdel(void **ptr);

/*
**	String utility functions
*/
char							*obj_strnew(size_t size);
char							**obj_strsplit(char const *str, char c);
size_t							obj_strsplit_len(char **split);
void							obj_strsplit_destroy(char **split);
char							*obj_strsub(char const *s, \
											unsigned int start, \
											size_t len);
char							*obj_strtrim(char *s);

#endif
