/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 21:20:25 by mravily           #+#    #+#             */
/*   Updated: 2020/10/17 18:31:10 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Draw le fuck a l'ecran en fonction de la touche tir appuyer
*/

void		fuck(void)
{
	t_vector	pos;
	t_vector	size;

	pos = create_vector(g_engine->config->resolution.x / 2.7
			, g_engine->config->resolution.y / 1.36);
	size = create_vector(g_engine->config->resolution.x / 3.8
			, g_engine->config->resolution.y / 3.8);
	if (g_engine->event->shoot_right == true
		&& g_engine->event->fuck_right == true)
		draw_weapon_texture(1, pos, size);
	else if (g_engine->event->shoot_right == false
		&& g_engine->event->fuck_right == true
		&& g_engine->event->shoot_left == false
		&& g_engine->event->fuck_left == false)
		draw_weapon_texture(0, pos, size);
	else if (g_engine->event->shoot_left == true
		&& g_engine->event->fuck_left == true)
		draw_weapon_texture(3, pos, size);
	else if (g_engine->event->shoot_left == false
		&& g_engine->event->fuck_left == true
		&& g_engine->event->shoot_right == false
		&& g_engine->event->fuck_right == false)
		draw_weapon_texture(2, pos, size);
}

/*
** Draw les poings et l'animation des coup de poings
*/

void		melee(void)
{
	t_vector	pos;
	t_vector	size;

	pos = create_vector(g_engine->config->resolution.x / 2.665
			, g_engine->config->resolution.y / 1.348);
	size = create_vector(g_engine->config->resolution.x / 3.8
			, g_engine->config->resolution.y / 3.8);
	if (g_engine->event->shoot_right == false
		&& g_engine->event->shoot_left == false)
		draw_weapon_texture(9, pos, size);
	else if (g_engine->event->shoot_right == true)
		draw_weapon_texture(10, pos, size);
	else if (g_engine->event->shoot_left == true)
		draw_weapon_texture(11, pos, size);
}

/*
** Animation de la chauffe et du tir du mini_gun
*/

void		mini_gun_firing(t_vector pos, t_vector size)
{
	if (g_engine->bonus->weapon->part_mini_gun >= 16
		&& g_engine->bonus->weapon->part_mini_gun <= 19
		&& g_engine->player->inventory->ammo != 0)
	{
		wait_time(20);
		draw_weapon_texture(g_engine->bonus->weapon->part_mini_gun
			, pos, size);
		if ((g_engine->bonus->weapon->part_mini_gun += 1) == 19)
			g_engine->bonus->weapon->part_mini_gun = 16;
		else
			g_engine->bonus->weapon->part_mini_gun += 1;
		g_engine->player->inventory->ammo -= 1;
	}
	else if (g_engine->bonus->weapon->part_mini_gun < 16
			&& g_engine->player->inventory->ammo != 0)
	{
		wait_time(30);
		draw_weapon_texture(g_engine->bonus->weapon->part_mini_gun
			, pos, size);
		g_engine->bonus->weapon->part_mini_gun += 1;
	}
	else
		fuck();
}

void		mini_gun(void)
{
	t_vector	pos;
	t_vector	size;

	pos = create_vector(g_engine->config->resolution.x / 2.665
			, g_engine->config->resolution.y / 1.348);
	size = create_vector(g_engine->config->resolution.x / 3.8
		, g_engine->config->resolution.y / 3.8);
	if (g_engine->event->shoot_right == false
		&& g_engine->event->shoot_left == false)
		draw_weapon_texture(13, pos, size);
	if (g_engine->event->shoot_right == true
		|| g_engine->event->shoot_left == true)
		mini_gun_firing(pos, size);
}

/*
** Draw l'arme en fonction de la du slot en cours
*/

void		weapon(void)
{
	if (g_engine->player->inventory->slot_1 == true)
	{
		if (g_engine->event->fuck == true)
			fuck();
		else
			melee();
	}
	if (g_engine->player->inventory->slot_2 == true)
	{
		if (g_engine->player->inventory->mini_gun == true)
			mini_gun();
		else
			melee();
	}
}
