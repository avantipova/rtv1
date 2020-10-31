# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldeirdre <ldeirdre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/28 18:22:57 by ldeirdre          #+#    #+#              #
#    Updated: 2020/10/31 18:52:21 by ldeirdre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

LNAM = libft/libft.a
LSDL = lib_sdl/libSDL2.a


LIBFDIR = ./libft/
LSDLDIR = ./SDL2/

OTHER = ./lib_sdl/


INCL = ./include/

SRC = main.c ft_vecdot.c ft_veclen.c ft_vecnorm.c ft_vecplaneinter.c ft_vecscale.c ft_vecsphereinter.c ft_vecsum.c \
		init_rtv.c read_scene.c render_scene.c run_app.c ft_vecconeinter.c ft_veccylinter.c ft_vecrot.c light.c

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
			@$(CC) -Wall -lft -lSDL2  -lm -L$(LIBFDIR) -L$(OTHER) $(OBJ) -framework OpenGL -I $(LIBFDIR) -I $(LSDLDIR) -I $(INCL) -o $(NAME)

$(OBJECTS_DIR)%.o: $(SRCSDIR)%.c $(INCL)/rtv_structs.h
			$(CC) -Wall  -g -c $< -I $(LIBFDIR) -I $(INCL) -I $(LSDLDIR) -o $@

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

