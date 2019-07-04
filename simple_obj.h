/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_obj.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:17:24 by fmessina          #+#    #+#             */
/*   Updated: 2019/07/04 16:21:53 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMPLE_OBJ_H
# define SIMPLE_OBJ_H

# ifdef DEBUG_SIMPLE_OBJ
#  define DEBUG_OBJ 1
# else
#  define DEBUG_OBJ	0
# endif

# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <time.h>
# include <stdarg.h>
# include <assert.h>

# define CHARSET_V				"v \t.-0123456789"
# define CHARSET_VT				"vt \t.-0123456789"
# define CHARSET_VN				"vn \t.-0123456789"
# define CHARSET_VP				"vp \t.-0123456789"
# define CHARSET_F				"f \t/-0123456789"
# define CHARSET_L 				"l \t-0123456789"

# define SIMPLE_OBJ_LOG_FILE "simpleOBJ.log"

# ifndef STRUCT_VEC3F
#  define STRUCT_VEC3F

/*
**	Vector 3 Floats [X Y Z]
*/
typedef struct					s_vec3f
{
	float						x;
	float						y;
	float						z;
}								t_vec3f;
# endif

/*
**	MESH DATA STRUCT:
**	-----------------
**	object		->	object name
**	group		->	object's group name
**	mtllib		->	mtllib specified file
**	usemtl		->	material file specified
**	shading		->	s line boolean
**
**	vertex		->	vertices array, defined with 4 components
**	n_vertex	->	number of vertices, [0] is preprocessing count,
**					[1] is for checksum and filling
**
**	face		->	face elements array
**	n_face		->	face elements settings:
**					[0] preprocessing count,
**					[1] checksum control,
**
**	normal		->	vertices normal array
**	n_normal	->	number of vertices normals:
**					[0] is preprocessing count,
**					[1] is for checksum and filling
**
**	texture		->	vertices texture coord array
**	n_texture	->	number of vertices texture coord:
**					[0] is preprocessing count,
**					[1] is for checksum and filling
**
**	space		->	space vertices array
**	n_space		->	number of space vertices:
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

	float						*vertex;
	size_t						n_vertex[2];

	int							*face;
	size_t						n_face[2];

	float						*normal;
	size_t						n_normal[2];

	float						*texture;
	size_t						n_texture[2];

	float						*space;
	size_t						n_space[2];

	t_vec3f						axis[2];
}								t_obj;

/*
**	simpleOBJ parser core functions
*/
t_obj							*obj_load_file(char *target);
t_obj							*obj_process_file(char **data);

/*
**	Parsing checksum functions
*/
bool							obj_checksum_preprocess(t_obj *obj, \
														char **split);
bool							obj_checksum_check(t_obj *obj);

/*
**	Line parsing functions
*/
bool							obj_line_process(t_obj *obj, char **split);
bool							obj_line_process_check(char *str, char *set);
bool							obj_line_process_f(t_obj *obj, char *str);
bool							obj_line_process_v(t_obj *obj, char *str);
bool							obj_line_process_vn(t_obj *obj, char *str);
bool							obj_line_process_vp(t_obj *obj, char *str);
bool							obj_line_process_vt(t_obj *obj, char *str);

/*
**	Data processing functions
*/
bool							obj_process_face(t_obj *obj, char *str);
bool							obj_process_face_data_dispatch(t_obj *obj, \
															char *str, \
															int mod, \
															int index);
bool							obj_process_face_quad(t_obj *obj, \
													char **split, int index);
bool							obj_process_face_triangle(t_obj *obj, \
													char **split, int index);
int								obj_process_face_type_get(char *sample);
bool							obj_process_normal(t_obj *obj, char *str);
bool							obj_process_space(t_obj *obj, char *str);
bool							obj_process_texture(t_obj *obj, char *str);
bool							obj_process_vertex(t_obj *obj, char *str);

/*
**	Vertex data processing functions
*/
bool							obj_process_vertex_xyz(t_obj *obj, \
														char **split, \
														size_t i);
bool							obj_process_vertex_xyzw(t_obj *obj, \
														char **split, \
														size_t i);
bool							obj_process_vertex_xyzrgb(t_obj *obj, \
														char **split, \
														size_t i);
bool							obj_process_vertex_xyzrgba(t_obj *obj, \
														char **split, \
														size_t i);
bool							obj_process_vertex_xyzwrgba(t_obj *obj, \
														char **split, \
														size_t i);
bool							obj_hue_process(t_obj *obj, \
												const int i, \
												const int mod);

/*
**	Error handling functions
*/
void							*obj_error(const char *message, void *trash);
bool							obj_berror(const char *message, void *trash);

/*
**	Logging functions
*/
bool							obj_log_init(const char *message, ...);
bool							obj_log(const char *message, ...);
bool							obj_log_error(const char *message, ...);

/*
**	Data printing functions
*/
void							obj_print_data(t_obj *obj);
void							obj_print_data_face(t_obj *obj);
void							obj_print_data_normal(t_obj *obj);
void							obj_print_data_texture(t_obj *obj);
void							obj_print_data_vertex(t_obj *obj);

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
