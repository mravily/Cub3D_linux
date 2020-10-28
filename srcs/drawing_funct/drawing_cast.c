/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_cast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 00:30:07 by mravily           #+#    #+#             */
/*   Updated: 2020/10/28 16:13:31 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		draw_wall(int x, t_color color)
{
	int		y;
	int		draw_end;

	y = g_engine->ray_cast->draw_start;
	draw_end = g_engine->ray_cast->draw_end;
	while (y < draw_end)
	{
		my_mlx_pixel_put(x, y, color);
		y++;
	}
}

/*
** Allume le pixel a la coordonnee x et y avec la couleur en int
*/

void		my_mlx_pixel_put_int(int x, int y, int color)
{
	t_image		*image;
	char		*dst;

	if (x < 0 || x > g_engine->config->resolution.x
		|| y < 0 || y > g_engine->config->resolution.y)
		return ;
	image = g_engine->image;
	dst = image->addr + (y * image->line_length + x
		* (image->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void		draw_texture_wall(t_config *config, int x)
{
	int			y;
	int			draw_end;

	draw_end = g_engine->ray_cast->draw_end;
	y = g_engine->ray_cast->draw_start;
	while (y < draw_end)
	{
		config->wall_tex_y = (int)config->tex_pos
			& (config->texture[NORTH].height - 1);
		config->tex_pos += config->step;
		my_mlx_pixel_put_int(x, y
			, (int)g_engine->config->wall_color[config->wall_tex_y
				* config->texture[NORTH].height
				+ config->wall_tex_x]);
		y++;
	}
}

void		draw_ceiling_and_floor(int x, float height)
{
	int			draw_end;
	int			y;
	t_color		ceiling;
	t_color		floor;

	draw_end = g_engine->ray_cast->draw_end;
	floor = g_engine->config->floor_color;
	ceiling = g_engine->config->ceiling_color;
	if (draw_end < 0)
		draw_end = height;
	y = draw_end;
	while (y < height)
	{
		my_mlx_pixel_put(x, y, floor);
		my_mlx_pixel_put(x, height - y - 1, ceiling);
		y++;
	}
}
