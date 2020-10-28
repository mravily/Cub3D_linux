/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 17:39:35 by mravily           #+#    #+#             */
/*   Updated: 2020/10/28 14:52:50 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				raycasting(void)
{
	int			x;
	float		width;
	float		height;
	char		**world_map;

	width = g_engine->config->resolution.x;
	height = g_engine->config->resolution.y;
	world_map = g_engine->config->map;
	x = 0;
	while (x < width)
	{
		calc_ray_dir_and_delta(g_engine->player, g_engine->ray_cast, x, width);
		calc_step_and_side_dist(g_engine->player, g_engine->ray_cast);
		perform_dda(g_engine->ray_cast, world_map);
		calc_perp_wall_dist(g_engine->ray_cast, g_engine->player);
		calc_line_height_and_draw_point(g_engine->ray_cast, height);
		calculate_texture(g_engine->ray_cast, g_engine->player
			, g_engine->config, height);
		calculate_color(g_engine->ray_cast, g_engine->player, g_engine->config);
		draw_texture_wall(g_engine->config, x);
		draw_ceiling_and_floor(x, height);
		g_engine->sprite_cast->z_buffer[x] = g_engine->ray_cast->perp_wall_dist;
		x++;
	}
	sprite_casting();
}
