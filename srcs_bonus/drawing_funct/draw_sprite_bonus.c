/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 22:18:03 by mravily           #+#    #+#             */
/*   Updated: 2020/10/17 18:20:23 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Draw le pixel du sprite
*/

static void		my_mlx_pixel_put_sprite(int x
	, int y, int color)
{
	t_image		*image;
	char		*dst;

	image = g_engine->image;
	dst = image->addr + (y * image->line_length + x
		* (image->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void			draw_pixel_sprite(int stripe
	, int draw_start_y, int i)
{
	my_mlx_pixel_put_sprite(stripe, draw_start_y
		, (int)g_engine->config->sprite_color
		[g_engine->config->texture
		[g_engine->config->sprite[i].id_texture].width
		* g_engine->sprite_cast->tex_y
		+ g_engine->sprite_cast->tex_x]);
}

static void		get_place(int draw_start_y
	, int stripe, int i)
{
	init_tex_y(g_engine->sprite_cast, g_engine->config, draw_start_y, i);
	g_engine->config->sprite_color = g_engine->config->texture
		[g_engine->config->sprite[i].id_texture].color;
	if ((g_engine->config->sprite_color
		[g_engine->config->texture
		[g_engine->config->sprite[i].id_texture].width
		* g_engine->sprite_cast->tex_y
			+ g_engine->sprite_cast->tex_x] & 0x00FFFFFF) != 0
		&& g_engine->config->sprite[i].active == true)
		draw_pixel_sprite(stripe, draw_start_y, i);
}

static int		get_place_2(int draw_start_y
	, int stripe, int i)
{
	draw_start_y = g_engine->sprite_cast->draw_start_y;
	while (draw_start_y < g_engine->sprite_cast->draw_end_y)
	{
		get_place(draw_start_y, stripe, i);
		draw_start_y++;
	}
	return (draw_start_y);
}

/*
** Algo pour draw le sprite
*/

void			draw_sprite(int i)
{
	int				stripe;
	int				draw_end_x;
	int				draw_start_y;

	stripe = g_engine->sprite_cast->draw_start_x;
	draw_end_x = g_engine->sprite_cast->draw_end_x;
	while (stripe < draw_end_x)
	{
		init_tex_x(g_engine->sprite_cast, g_engine->config, stripe, i);
		if (g_engine->sprite_cast->transform_y > 0
			&& stripe > 0
			&& stripe < g_engine->config->resolution.x
			&& g_engine->sprite_cast->transform_y
				< g_engine->sprite_cast->z_buffer[stripe])
		{
			draw_start_y = get_place_2(draw_start_y, stripe, i);
		}
		stripe++;
	}
}
