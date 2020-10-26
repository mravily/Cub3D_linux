/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 22:01:31 by mravily           #+#    #+#             */
/*   Updated: 2020/10/17 18:33:33 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		start_screen(void)
{
	t_welcome_tex		*welcome;
	t_vector			coord;
	t_vector			size;

	welcome = g_engine->bonus->welcome;
	coord = create_vector(0, g_engine->config->resolution.y / 2.5);
	size = create_vector(g_engine->config->resolution.x
		, g_engine->config->resolution.y / 5);
	draw_welcome_texture(welcome, coord, size);
}

void		game_over_screen(void)
{
	t_welcome_tex		*game_over;
	t_vector			coord;
	t_vector			size;

	game_over = g_engine->bonus->game_over;
	coord = create_vector(0, g_engine->config->resolution.y / 2.5);
	size = create_vector(g_engine->config->resolution.x
		, g_engine->config->resolution.y / 5);
	draw_welcome_texture(game_over, coord, size);
}
