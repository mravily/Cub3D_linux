/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 17:08:18 by mravily           #+#    #+#             */
/*   Updated: 2020/10/17 18:24:02 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		bool_move(int key)
{
	if (key == W_KEY)
		g_engine->event->forward = true;
	if (key == A_KEY)
		g_engine->event->left = true;
	if (key == S_KEY)
		g_engine->event->backward = true;
	if (key == D_KEY)
		g_engine->event->right = true;
	if (key == LEFT_KEY)
		g_engine->event->rotate_left = true;
	if (key == RIGHT_KEY)
		g_engine->event->rotate_right = true;
}

int				handle_key_pressed(int key, void *params)
{
	t_engine *engine;

	engine = (t_engine *)params;
	if (key == ESC_KEY)
		exit_cub(g_engine);
	re_set_dir_player(key, g_engine->player, g_engine->event);
	if (g_engine->event->start == true)
	{
		bool_move(key);
		event_pressed_bonus(key);
	}
	if (g_engine->player->health == 0)
	{
		if (key == RTN_KEY)
		{
			g_engine->player->dir = g_engine->player->start_dir;
			g_engine->player->plane = g_engine->player->start_plane;
			g_engine->player->pos = g_engine->player->start_pos;
			g_engine->player->health = 100;
		}
	}
	return (0);
}
