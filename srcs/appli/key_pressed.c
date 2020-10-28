/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 17:08:18 by mravily           #+#    #+#             */
/*   Updated: 2020/10/28 15:16:35 by mravily          ###   ########.fr       */
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
	bool_move(key);
	return (0);
}
