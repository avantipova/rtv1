# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldeirdre <ldeirdre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/28 18:22:57 by ldeirdre          #+#    #+#              #
#    Updated: 2020/12/03 20:49:48 by ldeirdre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

LNAM = libft/libft.a
LSDL = lib_sdl/libSDL2.a


LIBFDIR = ./libft/
LSDLDIR = ./SDL2/

OTHER = ./lib_sdl/


INCL = ./include/

SRC =	main.c ft_vecop.c ft_vecplaneinter.c ft_vecsphereinter.c \
		init_rtv.c read_scene.c render_scene.c ft_vecconeinter.c \
		ft_veccylinter.c ft_vecrot.c light.c valid_file.c move_scene.c \
		list_op.c

SRCSDIR = ./src/

SRCS = $(addprefix $(SRCSDIR), $(SRC))

OBJECTS_DIR = ./objects/

OBJECT_FILE = $(SRC:.c=.o)

OBJ = $(addprefix $(OBJECTS_DIR), $(OBJECT_FILE))

CC = gcc
CCFL = -Wall -Wextra -Werror
all: $(NAME)

$(LNAM):
			@make -C $(LIBFDIR)

$(NAME): $(OBJECTS_DIR) $(OBJ)
			@make -C $(LIBFDIR)
			@$(CC) $(CCFL) -lft -lSDL2 -lm -L$(LIBFDIR) -L$(OTHER) $(OBJ) -framework OpenGL -I $(LIBFDIR) -I $(LSDLDIR) -I $(INCL) -o $(NAME)

$(OBJECTS_DIR)%.o: $(SRCSDIR)%.c $(INCL)/rtv_structs.h
			$(CC) $(CCFL) -g -c $< -I $(LIBFDIR) -I $(INCL) -I $(LSDLDIR) -o $@

$(OBJECTS_DIR):
			@mkdir $(OBJECTS_DIR)

clean:
			@rm -f $(OBJ)
			@make -C libft/ clean

fclean: clean
			@rm -f $(NAME)
			@make -C libft/ fclean

re: fclean all

.PHONY: all, clean, fclean, re

