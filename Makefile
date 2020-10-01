# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mravily <mravily@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/04 13:40:02 by mravily           #+#    #+#              #
#    Updated: 2020/10/01 12:55:35 by mravily          ###   ########.fr        #
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
NAME = Cub3D

CC =   clang
LIB_DIR = $(shell find lib -type d)
INC_DIR = $(shell find includes -type d) $(shell find lib/libft/includes -type d) \
			lib/mlx_linux/mlx.h
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

LINUXFLAG	= -lm -lX11 -lXext
CFLAGS = -Werror -Wall -Wextra -fsanitize=address -g
IFLAGS = $(foreach dir, $(INC_DIR), -I$(dir) )
LFLAGS = $(foreach dir, $(LIB_DIR), -L$(dir) ) $(foreach lib, $(LIB), -l$(lib)) $(LINUXFLAG)


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
all		:
	$(CC) $(LFLAGS) $(IFLAGS) $(OBJ) -o $(NAME)
	
	
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
	mkdir -p $(OBJ_DIR)
	gcc $(CFLAGS) $(IFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) $(OBJ) -o $@

debug : $(NAME)
	@./$(NAME)

install :
	@make -C lib/libft
	@make -C lib/mlx_linux

re-install :
	@make -C lib/libft re
	@make -C lib/mlx_linux re

fclean-install:
	@$(foreach dir, $(LIB_DIR), make -C $(dir) fclean;)

clean	:
	@rm -rf $(OBJ)

fclean	: clean
	@rm -rf $(NAME)

re		: fclean all

.PHONY: all show install re-install re clean flcean