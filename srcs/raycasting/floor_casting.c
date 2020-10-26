/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_casting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 19:33:44 by mravily           #+#    #+#             */
/*   Updated: 2020/10/26 16:49:12 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Initialisation de floor_wall
** ray_cast->side == 0 && ray_cast->ray_dir.x > 0 == NORD
** ray_cast->side == 0 && ray_cast->ray_dir.x < 0 == SUD
** ray_cast->side == 1 && ray_cast->ray_dir.y > 0 == EST
** else WEST
*/

static void				init_floor_wall(t_floor_cast *floor_cast
	, t_ray_cast *ray_cast)
{
	if (ray_cast->side == 0 && ray_cast->ray_dir.x > 0)
	{
		floor_cast->floor_wall_x = ray_cast->map_x;
		floor_cast->floor_wall_y = ray_cast->map_y + ray_cast->wall_x;
	}
	else if (ray_cast->side == 0 && ray_cast->ray_dir.x < 0)
	{
		floor_cast->floor_wall_x = ray_cast->map_x + 1.0;
		floor_cast->floor_wall_y = ray_cast->map_y + ray_cast->wall_x;
	}
	else if (ray_cast->side == 1 && ray_cast->ray_dir.y > 0)
	{
		floor_cast->floor_wall_x = ray_cast->map_x + ray_cast->wall_x;
		floor_cast->floor_wall_y = ray_cast->map_y;
	}
	else
	{
		floor_cast->floor_wall_x = ray_cast->map_x + ray_cast->wall_x;
		floor_cast->floor_wall_y = ray_cast->map_y + 1.0;
	}
}

/*
** Initialitation de current_floor
** Position en cours du joueur sur la carte
*/

static void				init_current_floor(t_floor_cast *floor_cast
	, t_player *player)
{
	floor_cast->current_floor_x = floor_cast->weight
		* floor_cast->floor_wall_x
		+ (1.0 - floor_cast->weight) * player->pos.x;
	floor_cast->current_floor_y = floor_cast->weight
		* floor_cast->floor_wall_y
		+ (1.0 - floor_cast->weight) * player->pos.y;
}

/*
** Initialisation de floor_tex
** position de la texture sur x et y
*/

static void				init_floor_tex(t_floor_cast *floor_cast
	, t_config *config)
{
	if (g_engine->config->floor_w == path)
	{
		floor_cast->floor_tex_x = (int)(floor_cast->current_floor_x
			* config->texture[FLOOR].width)
			% config->texture[FLOOR].width;
		floor_cast->floor_tex_y = (int)(floor_cast->current_floor_y
			* config->texture[FLOOR].height)
			% config->texture[FLOOR].height;
	}
	else if (g_engine->config->ceiling_w == path)
	{
		floor_cast->floor_tex_x = (int)(floor_cast->current_floor_x
			* config->texture[CEILING].width)
			% config->texture[CEILING].width;
		floor_cast->floor_tex_y = (int)(floor_cast->current_floor_y
			* config->texture[CEILING].height)
			% config->texture[CEILING].height;
	}
}

/*
** Draw les textures a l'écran du sol et plafond
*/

static void				draw_tex_floor_ceiling(t_floor_cast *floor_cast
	, int x, int y)
{
	t_config		*config;
	int				height;

	height = g_engine->config->resolution.y;
	config = g_engine->config;
	if (config->floor_w == path)
	{
		if (floor_cast->floor_tex_x >= 0 && floor_cast->floor_tex_y >= 0)
			my_mlx_pixel_put_int(x, y
				, config->floor_color_tex[config->texture[FLOOR].width
					* floor_cast->floor_tex_y
					+ floor_cast->floor_tex_x]);
	}
	if (config->ceiling_w == path)
	{
		if (floor_cast->floor_tex_x >= 0 && floor_cast->floor_tex_y >= 0)
			my_mlx_pixel_put_int(x, height - y - 1
				, (int)config->ceiling_color_tex[config->texture[CEILING].height
					* floor_cast->floor_tex_y
					+ floor_cast->floor_tex_x]);
	}
}

/*
** Algorithme pour afficher un texture sur le sol et le plafond
*/

void					floor_casting(int height, int x)
{
	t_floor_cast		*floor_cast;
	t_player			*player;
	int					draw_end;
	int					y;

	player = g_engine->player;
	draw_end = g_engine->ray_cast->draw_end;
	*(g_engine->bonus->floor_cast) = create_floor_cast(g_engine->ray_cast);
	floor_cast = g_engine->bonus->floor_cast;
	init_floor_wall(floor_cast, g_engine->ray_cast);
	y = draw_end;
	while (y < height)
	{
		floor_cast->current_dist = height / (2.0 * y - height);
		floor_cast->weight = (floor_cast->current_dist
			- floor_cast->dist_player)
			/ (floor_cast->dist_wall - floor_cast->dist_player);
		init_current_floor(floor_cast, player);
		init_floor_tex(floor_cast, g_engine->config);
		draw_tex_floor_ceiling(floor_cast, x, y);
		y++;
	}
}
