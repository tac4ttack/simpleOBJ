# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 12:17:28 by fmessina          #+#    #+#              #
#    Updated: 2019/07/01 15:34:27 by fmessina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		simpleOBJ.a

CC =		clang
CFLAGS +=	-Wall -Wextra -Werror $(DEBUGFLAGS) $(ASANFLAGS)

SRC =		obj_clean.c \
			obj_error.c \
			obj_line_process.c \
			obj_line_process_check.c \
			obj_line_process_f.c \
			obj_line_process_v.c \
			obj_line_process_vn.c \
			obj_line_process_vp.c \
			obj_line_process_vt.c \
			obj_load_file.c \
			obj_log.c \
			obj_print_data_face.c \
			obj_print_data_normal.c \
			obj_print_data_texture.c \
			obj_print_data_vertex.c \
			obj_print_data.c \
			obj_process_face.c \
			obj_process_face_data.c \
			obj_process_face_get_type.c \
			obj_process_face_quad.c \
			obj_process_face_triangle.c \
			obj_process_file.c \
			obj_process_normal.c \
			obj_process_space.c \
			obj_process_texture.c \
			obj_process_vertex.c \
			obj_strnew.c \
			obj_strsplit.c \
			obj_strsub.c \
			obj_strtrim.c

OFILES =	$(SRC:.c=.o)

all: Makefile simple_obj.h $(NAME)

$(NAME): simple_obj.h $(SRC) $(OFILES)
	@echo "Object files successfully created"
	@echo "Building library $(NAME)..."
	@ar rc $(NAME) $(OFILES)
	@echo "Library successfully created"
	@echo "Indexing..."
	@ranlib $(NAME)
	@echo "Library indexed\n"

debug:
	$(eval DEBUGFLAGS = -DDEBUG_SIMPLE_OBJ -g)

debug_asan: debug
	$(eval ASANFLAGS = -fsanitize=address -fno-omit-frame-pointer)

clean:
	@echo "Cleaning object files..."
	@/bin/rm -f $(OFILES)
	@echo "Object files deleted\n"

fclean: clean
	@echo "Cleaning build and object path..."
	@/bin/rm -f $(NAME)
	@echo "'$(NAME)' file deleted\n"

re: fclean all

.PHONY: all clean fclean re simpleOBJ debug debug_asan
