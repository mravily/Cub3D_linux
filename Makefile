# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mravily <mravily@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/04 13:40:02 by mravily           #+#    #+#              #
#    Updated: 2020/04/13 19:15:12 by mravily          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

CC          =   gcc
LIB_DIR = lib/libft lib/mlx_linux
SRC_DIR = $(shell find srcs -type d)
INC_DIR = $(shell find includes -type d) $(shell find lib/libft -type d) \
		 $(shell find lib/mlx_linux -type d)
OBJ_DIR = obj

SRC = $(foreach dir, $(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.c), $(notdir $(file))))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))
LIB = ft mlx_linux #mlx
vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)
LINUXFLAG	=	-lm -lX11 -lXext
CFLAG = -Wall -Wextra #-fsanitize=address -g #-Werror 
IFLAG = $(foreach dir, $(INC_DIR), -I $(dir) )
LFLAG = $(foreach lib, $(LIB), -l $(lib) ) $(foreach dir, $(LIB_DIR), -L $(dir) ) $(LINUXFLAG)


# Colors

_GREY=	$'\e[30m
_RED=	$'\e[31m
_GREEN=	$'\e[32m
_YELLOW=$'\e[33m
_BLUE=	$'\e[34m
_PURPLE=$'\e[35m
_CYAN=	$'\e[36m
_WHITE=	$'\e[37m

all		: 	
	@echo "\n$(_BLUE)___$(NAME) Setting___\n$(_WHITE)"
	@make $(NAME)

show	:
	@echo "SRC_DIR : $(SRC_DIR)\n"
	@echo "LIB_DIR : $(LIB_DIR)\n"
	@echo "INC_DIR : $(INC_DIR)\n"
	@echo "CFLAG : $(CFLAG)\n"
	@echo "IFLAG : $(IFLAG)\n"
	@echo "LFLAG : $(LFLAG)\n"
	@echo "SRC :$(foreach file, $(SRC),\n\t$(file))\n"
	@echo "OBJ :$(foreach file, $(OBJ),\n\t$(file))\n"
	@echo "\n-----\n"
	@echo "$(_BLUE)Compiling : \n$(_YELLOW)$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(NAME)$(_WHITE)"

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAG) $(IFLAG) -c $< -o $@

$(NAME):
	@echo "-----\nCreating Binary File $(_YELLOW)$@$(_WHITE) ... \c"
	@$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(NAME)
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

debug : 		$(NAME)
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
	@rm -f $(OBJ)

fclean	: clean
	@rm -f $(NAME)

re		: fclean all

.PHONY: all show install re-install re clean flcean