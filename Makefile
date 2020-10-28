# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mravily <mravily@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/04 13:40:02 by mravily           #+#    #+#              #
#    Updated: 2020/10/28 16:25:49 by mravily          ###   ########.fr        #
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
LIB_DIR = lib/libft lib/mlx_linux
INC_DIR = $(shell find includes -type d) $(shell find lib/libft/includes -type d) \
			lib/mlx_linux/
			
# Chercher le dossier srcs
SRC_DIR = $(shell find srcs -type d)
# Chercher le dossier srcs
SRC_DIR_BONUS = $(shell find srcs_bonus -type d)

# Nom du dossier qui contiendra les fichiers .o
OBJ_DIR = obj
# Nom du dossier qui contiendra les fichiers objets bonus
OBJ_DIR_BONUS = obj_bonus

# Pour chaque dossier dans SRC_DIR, sort les tous les fichiers.c
SRC = $(foreach dir, $(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.c), $(notdir $(file))))
# Pour chaque dossier dans SRC_DIR_BONUS, sort les tous les fichiers bonus.c
SRC_BONUS = $(foreach dir, $(SRC_DIR_BONUS), $(foreach file, $(wildcard $(dir)/*_bonus.c), $(notdir $(file))))
#SRC_BONUS = exit_cub_bonus.c screen_shot_bonus.c how_many_char_bonus.c main_bonus.c \
        draw_sprite_bonus.c drawing_resize_tex_bonus.c  drawing_basic_bonus.c \
        init_tex_x_y_bonus.c  drawing_cast_bonus.c  is_wall_bonus.c is_sprite_bonus.c \
		is_parsing_bonus.c is_not_wall_bonus.c is_back_pack_sprite_bonus.c is_weapon_sprite_bonus.c \
		is_line_texture_bonus.c is_medikit_sprite_bonus.c is_space_bonus.c  is_cardi_point_bonus.c  \
        is_not_wall_sprite_bonus.c is_line_floor_ceiling_bonus.c is_shield_sprite_bonus.c is_item_bonus.c \
        sprite_casting_bonus.c swap_t_sprite_bonus.c calc_sprite_casting_bonus.c get_item_bonus.c \
        hit_enemy_bonus.c calc_sprite_bonus.c screen_image_bonus.c create_appli_bonus.c key_pressed_bonus.c \
        event_manager_bonus.c catch_key_bonus.c floor_casting_bonus.c raycasting_bonus.c calc_raycasting_bonus.c \
        play_sound_bonus.c delay_bonus.c draw_ath_bonus.c put_on_helmet_bonus.c helmet_drawing_bonus.c \
        destruct_helmet_bonus.c create_helmet_bonus.c init_tab_ath_bonus.c destruct_helmet_tex_bonus.c \
		create_helmet_tex_bonus.c create_img_hmlt_bonus.c destruc_img_hmlt_bonus.c create_weapon_bonus.c \
        weapon_bonus.c draw_weapon_bonus.c destruct_weapon_bonus.c create_weapon_tex_bonus.c \
        destruc_weapon_tex_bonus.c destruct_bonus.c create_bonus.c welcome_drawing_bonus.c \
        start_screen_bonus.c render_welcome_bonus.c destruct_welcome_tex_bonus.c create_welcome_tex_bonus.c \
        destruct_img_welc_bonus.c create_img_welc_bonus.c diagonal_movement_bonus.c normal_movement_bonus.c \
        player_bonus.c destruct_sprite_bonus.c create_sprite_bonus.c destroy_sprite_cast_bonus.c \
        create_sprite_cast_bonus.c destuct_t_player_bonus.c create_t_player_bonus.c creator_event_bonus.c \
        destruct_event_bonus.c destruct_floor_cast_bonus.c  create_floor_cast_bonus.c creator_engine_bonus.c \
        destruct_engine_bonus.c destruct_t_parsing_bonus.c create_t_parsing_bonus.c destruct_texture_bonus.c \
        create_texture_bonus.c destuct_image_bonus.c create_image_bonus.c creator_color_bonus.c \
        destruct_color_bonus.c creator_vector_bonus.c destruct_vector_bonus.c creator_vars_bonus.c \
        destruct_vars_bonus.c creator_ray_cast_bonus.c destruct_raycast_bonus.c \
        destruct_config_bonus.c create_config_bonus.c check_bonus.c parsing_bonus.c \
        get_color_bonus.c catch_error_bonus.c get_resolution_bonus.c dispatch_bonus.c \
        get_texture_bonus.c texture_assignment_bonus.c generate_textures_bonus.c \
        set_sprite_bonus.c map_bonus.c set_player_map_bonus.c
		
# Ajoute devant chaque fichier.o OBJ_DIR/
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))
# Ajoute devant chaque fichier.o OBJ_DIR/
OBJ_BONUS = $(addprefix $(OBJ_DIR_BONUS)/, $(SRC_BONUS:%.c=%.o))

LIB = ft mlx_Linux mlx

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)
vpath %.c $(foreach dir, $(SRC_DIR_BONUS), $(dir):)

LINUXFLAG	= -lm -lX11 -lXext -lbsd
CFLAGS = -Werror -Wall -Wextra -g #-fsanitize=address
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

$(OBJ_DIR_BONUS)/%.o : %.c
	@mkdir -p $(OBJ_DIR_BONUS)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	
$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(NAME): clean-bonus install $(OBJ) $(INC_DIR)
	@$(CC) $(CFLAGS) $(LFLAGS) $(OBJ) -o $@ \
	lib/mlx_linux/libmlx.a lib/mlx_linux/libmlx_Linux.a lib/libft/libft.a $(LINUXFLAG)

all		: $(NAME)
	
bonus	: fclean install $(OBJ_BONUS) $(INC_DIR)
	@$(CC) $(CFLAGS) $(LFLAGS) $(OBJ_BONUS) -o $(NAME) \
	lib/mlx_linux/libmlx.a lib/mlx_linux/libmlx_Linux.a lib/libft/libft.a $(LINUXFLAG)

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

clean	: clean-bonus
	@rm -rf $(OBJ_DIR)

clean-bonus :
	@rm -rf $(OBJ_DIR_BONUS)
	
fclean	: clean
	@rm -rf $(NAME)

re		: fclean all

.PHONY: all show install re-install re clean flcean