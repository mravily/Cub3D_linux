/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 16:42:17 by mravily           #+#    #+#             */
/*   Updated: 2020/10/28 16:13:21 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			handle_key_release(int key, void *params)
{
	t_engine	*engine;

	engine = (t_engine *)params;
	if (key == W_KEY)
		g_engine->event->forward = false;
	if (key == A_KEY)
		g_engine->event->left = false;
	if (key == S_KEY)
		g_engine->event->backward = false;
	if (key == D_KEY)
		g_engine->event->right = false;
	if (key == LEFT_KEY)
		g_engine->event->rotate_left = false;
	if (key == RIGHT_KEY)
		g_engine->event->rotate_right = false;
	return (0);
}
