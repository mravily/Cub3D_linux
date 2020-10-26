/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_engine.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:19:49 by mravily           #+#    #+#             */
/*   Updated: 2020/10/20 12:50:05 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_ENGINE_H
# define CUB3D_ENGINE_H

# include "cub3d_vars.h"
# include "cub3d_image.h"
# include "cub3d_player.h"
# include "cub3d_config.h"
# include "cub3d_parsing.h"
# include "cub3d_event.h"
# include "cub3d_ray_cast.h"
# include "cub3d_sprite_cast.h"
# include "cub3d_bonus.h"

typedef struct	s_engine
{
	t_vars			*vars;
	t_image			*image;
	t_parsing		*parsing;
	t_ray_cast		*ray_cast;
	t_sprite_cast	*sprite_cast;
	t_player		*player;
	t_config		*config;
	t_event			*event;
	t_bonus			*bonus;
}				t_engine;

/*
** Basic function for full raycasting (raycast, floorcast, ceilingcast)
*/

void			pre_check_file(int argc, char **argv);
void			init_engine(void);
void			raycasting(void);
void			render_game(void);
void			init_image (t_image *image, int width, int height);
void			floor_casting(int height, int x);
int				screen_shot(void);
void			event_pressed_bonus(int key);
void			sprite_casting(void);
void			init_tex_x(t_sprite_cast *sprite_cast, t_config *config
	, int stripe, int i);
void			init_tex_y(t_sprite_cast *sprite_cast, t_config *config
	, int draw_start_y, int i);
void			calculate_sprite(t_sprite_cast *sprite_cast, t_config *config
	, int i);

/*
** Function pour catch les erreurs et les affichers de facon specifiques
*/
void			error_exit_cub(char *line, char *str, char *message);
int				exit_screen_shot(void);

/*
** Mallocage ou creation structure
*/

char			**init_tab_path_helmet_tex(void);

t_weapon_tex	create_weapon_tex(char *path);
t_img_hlmt		create_img_hlmt(int width, int height);
t_helmet_tex	create_hlmt_tex(char *path);
t_texture		create_texture(char *path);
t_engine		*malloc_engine(char *title);
t_helmet		*malloc_helmet(void);
t_weapon		*malloc_weapon(void);
t_texture		*malloc_texture(char *path);
t_img_hlmt		*malloc_img_hlmt(int width, int height);
t_img_welc		*malloc_img_welc(int width, int height);
t_helmet_tex	*malloc_helmet_tex(char *path);
t_welcome_tex	*malloc_welcome_tex(char *path);

/*
** Free ou destroy structure
*/

void			destroy_helmet_tex(t_helmet_tex to_destroy);
void			destroy_welcome_tex(t_vars vars, t_welcome_tex to_destroy);
void			destroy_texture(t_texture to_destroy);
void			destroy_config(t_config to_destroy);

void			free_config(t_config *to_free);
void			free_texture(t_texture *to_free);
void			free_engine(void);
void			free_helmet(t_helmet *to_free);
void			free_img_hlmt(t_img_hlmt *to_free);
void			free_helmet_tex(t_helmet_tex *to_free);
void			free_welcome_tex(t_vars *vars, t_welcome_tex *to_free);

/*
** Drawing Function
*/

void			compteur_shield(void);
void			compteur_health(void);
void			draw_sprite(int i);
void			draw_health(void);
void			draw_blue_shield(void);
void			draw_green_shield(void);
void			draw_weapon_texture(int nb, t_vector coord
	, t_vector size);
void			draw_hlmt_texture(int nb, t_vector coord
	, t_vector size);
void			draw_welcome_texture(t_welcome_tex *welcome
	, t_vector coord, t_vector size);
void			my_mlx_pixel_put_hlmt(t_img_hlmt *img_hlmt, int x, int y
	, t_color color);
void			my_mlx_pixel_put_welcome(int x, int y
	, t_color color);

t_color			hlmt_get_color(t_helmet_tex *helmet, int x, int y);
void			put_on_the_helmet(void);
void			start_screen(void);

void			fuck(void);
void			melee(void);
void			mini_gun_firing(t_vector pos, t_vector size);
void			mini_gun(void);
void			weapon(void);
void			game_over_screen(void);

void			render_welcome(void);
void			render_ath(void);

/*
** Movement function
*/

bool			is_not_wall_sprite(t_vector index, char **map);
void			simple_move(t_player *player, t_event *event
	, float mov_speed, char **world_map);
void			diagonal_movement(t_player *player, t_event *event
	, float mov_speed, char **world_map);
void			draw_ath_texture(int nb, t_vector coord
	, t_vector size);

#endif
