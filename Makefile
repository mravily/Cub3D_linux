# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mravily <mravily@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/04 13:40:02 by mravily           #+#    #+#              #
#    Updated: 2020/10/26 15:32:38 by mravily          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# $@ Nom de la cible
# Cible == $(NAME) : Dependance == main.o player.o
#	$(CC) -o $@ == $NAME
# $< Premiere dependence
# $^ liste de dependences
# $? liste des dependence plus recente que la cible
# $* nom du fichier sans son extension

#gcc -o <ficher de sortie> -c <fichier source> [FLAGS]
NAME = cub3D

CC =   clang
LIB_DIR = lib/libft lib/mlx_linux
INC_DIR = $(shell find includes -type d) $(shell find lib/libft/includes -type d) \
			lib/mlx_linux/
# Chercher le dossier srcs
SRC_DIR = $(shell find srcs -type d)
# Nom du dossier qui contiendra les fichiers .o
OBJ_DIR = obj
# Pour chaque dossier dans SRC_DIR, sort les tous les fichiers.c
SRC = $(foreach dir, $(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.c), $(notdir $(file))))
# Ajoute devant chaque fichier.o OBJ_DIR/
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

LIB = ft mlx_Linux mlx

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

LINUXFLAG	= -lm -lX11 -lXext -lbsd
CFLAGS = -Werror -Wall -Wextra -g -fsanitize=address
IFLAGS = $(foreach dir, $(INC_DIR), -I$(dir) )
LFLAGS = $(foreach dir, $(LIB_DIR), -L$(dir) ) $(foreach lib, $(LIB), -l $(lib))

# Colors

_GREY=	$'\e[30m
_RED=	$'\e[31m
_GREEN=	$'\e[32m
_YELLOW=$'\e[33m
_BLUE=	$'\e[34m
_PURPLE=$'\e[35m
_CYAN=	$'\e[36m
_WHITE=	$'\e[37m

#$(CC) $(LFLAGS) $(IFLAGS) $(OBJ) -o $(NAME)
all		: $(NAME)

show	:
	@echo "SRC_DIR : $(SRC_DIR)\n"
	@echo "LIB_DIR : $(LIB_DIR)\n"
	@echo "INC_DIR : $(INC_DIR)\n"
	@echo "CFLAG : $(CFLAGS)\n"
	@echo "IFLAG : $(IFLAGS)\n"
	@echo "LFLAG : $(LFLAGS)\n"
	@echo "SRC :$(foreach file, $(SRC),\n\t$(file))\n"
	@echo "OBJ :$(foreach file, $(OBJ),\n\t$(file))\n"
	@echo "\n-----\n"
	@echo "$(_BLUE)Compiling : \n$(_YELLOW)$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(NAME)$(_WHITE)"

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(INC_DIR)
	@$(CC) $(CFLAGS) $(LFLAGS) $(OBJ) -o $@ lib/mlx_linux/libmlx.a lib/mlx_linux/libmlx_Linux.a lib/libft/libft.a $(LINUXFLAG)

debug : $(NAME)
	@./$(NAME)

install :
	@make -C lib/libft
	@make -C lib/mlx_linux

re-install :
	@make -C lib/libft re
	@make -C lib/mlx_linux re

fclean-install:
	@make -C lib/libft fclean
	@make -C lib/mlx_linux clean

clean	:
	@rm -rf $(OBJ_DIR)

fclean	: clean
	@rm -rf $(NAME)

re		: fclean all

.PHONY: all show install re-install re clean flcean