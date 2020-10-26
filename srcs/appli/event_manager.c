/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 16:42:17 by mravily           #+#    #+#             */
/*   Updated: 2020/10/21 16:12:24 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		choice_inventory(int key)
{
	if (key == K1_KEY)
	{
		g_engine->player->inventory->slot_1 = true;
		g_engine->player->inventory->slot_2 = false;
	}
	if (key == K2_KEY)
	{
		g_engine->player->inventory->slot_2 = true;
		g_engine->player->inventory->slot_1 = false;
	}
}

void		event_pressed_bonus(int key)
{
	if (key == LSFT_KEY)
	{
		g_engine->event->run = true;
		g_engine->player->mov_speed *= 1.5;
	}
	if (key == F_KEY)
	{
		if (g_engine->event->fuck == true)
			g_engine->event->fuck = false;
		else
			g_engine->event->fuck = true;
	}
	if (key == LCTRL_KEY)
	{
		g_engine->event->shoot_left = true;
		g_engine->event->fuck_left = true;
		g_engine->bonus->weapon->part_mini_gun = 12;
	}
	if (key == RCTRL_KEY)
	{
		g_engine->event->shoot_right = true;
		g_engine->event->fuck_right = true;
		g_engine->bonus->weapon->part_mini_gun = 12;
	}
	choice_inventory(key);
}

void		event_release_bonus(int key)
{
	if (key == LSFT_KEY)
	{
		g_engine->event->run = false;
		g_engine->player->mov_speed = g_engine->player->start_mov_speed;
	}
	if (key == LCTRL_KEY)
	{
		g_engine->event->shoot_left = false;
		if (g_engine->event->fuck_left == true)
			g_engine->event->fuck_right = false;
	}
	if (key == RCTRL_KEY)
	{
		g_engine->event->shoot_right = false;
		if (g_engine->event->fuck_right == true)
			g_engine->event->fuck_left = false;
	}
}

int			handle_key_release(int key, void *params)
{
	t_engine	*engine;

	engine = (t_engine *)params;
	if (g_engine->event->start == true)
	{
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
		event_release_bonus(key);
	}
	return (0);
}
