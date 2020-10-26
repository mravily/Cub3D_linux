/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parsing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:42:30 by mravily           #+#    #+#             */
/*   Updated: 2020/10/26 17:09:39 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PARSING_H
# define CUB3D_PARSING_H

# include "cub3d_engine.h"
# include "cub3d_config.h"
# include "cub3d_player.h"
# include "cub3d_image.h"
# include "cub3d_ray_cast.h"
# include "cub3d_texture.h"

#define MAX_LEN     512
 
typedef struct	s_parsing
{
	bool	resolution;
	bool	north;
	bool	south;
	bool	west;
	bool	east;
	bool	sprite;
	bool	floor;
	bool	ceiling;
	bool	map;
	bool	player;
}				t_parsing;

t_parsing		*malloc_parsing(void);
void			free_parsing(t_parsing *to_free);

bool			check_argument(int nb, char *to_check, char *argv);
bool			check_texture_path(char *path);
void			check_line(char *line);
void			check_line_map(char *line, t_config *config);
void			check_map(t_config *config, t_player *player);
void			check_tab_line(char *char_allowed, char **tab);
void			check_around(char **map, t_vector index);
void			check_and_set_sprite(t_config *config, char **map
	, t_vector index);
	
void			dispatch(char *line, int i);
void			get_resolution(char *line, t_config *config);
void			get_texture(int id, char *line);
void			get_color(int id, char *line);
void			get_map(char *line, t_config *config);
void			texture_assignment(int id, char *path);
void			generate_texture(t_texture *texture, t_image *image);
void			parsing_cub(char *argv);
void			set_player(char **map, t_vector index, t_player *player);
int 			how_many_char(char *str, char c);

bool			is_wall(char **map, t_vector index);
bool			is_space(t_vector index, char **map);
bool			is_sprite(char **map, t_vector index, char *list_sprite);
bool			is_med_kit(char **map, t_vector index);
bool			is_back_pack(char **map, t_vector index);
bool			is_shield(char **map, t_vector index);
bool			is_line_floor_ceiling(char *line, int i);
bool			is_line_texture(char *line, int i);
bool			is_floor_line(char *line, int i);
bool			is_ceiling_line(char *line, int i);
bool			is_sprite_line(char *line, int i);
bool			is_resolution_line(char *line, int i);

void			error_color(int id, char **tab, char *line);
void			error_line(int id, char *line);
void			error_rgb(int id, char **tab, char *color);
void			error_path(int id, char *line);
void			error_resolution(int id, char *line);

#endif
