/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_on_helmet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 01:06:09 by mravily           #+#    #+#             */
/*   Updated: 2020/10/21 16:19:17 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Draw le logo de run a l'ecran
*/

void		draw_ath_run(void)
{
	if (g_engine->event->run == true)
	{
		draw_hlmt_texture(16
			, create_vector(g_engine->config->resolution.x / 23
				, g_engine->config->resolution.y / 1.4)
			, create_vector(g_engine->config->resolution.x / 10
				, g_engine->config->resolution.y / 10));
	}
}

/*
** Draw l'ATH Health bar et Shield Bar
*/

void		draw_shield_health(void)
{
	draw_health();
	compteur_health();
	compteur_shield();
	if (g_engine->player->shield >= 25 && g_engine->player->shield <= 100)
		draw_green_shield();
	if (g_engine->player->shield >= 125 && g_engine->player->shield <= 200)
		draw_blue_shield();
}

/*
** Draw le compteur de munition
*/

void		draw_number_ammo(void)
{
	t_vector		pos;
	t_vector		size;

	pos = create_vector(g_engine->config->resolution.x / 1.34
		, g_engine->config->resolution.y / 1.16);
	size = create_vector(g_engine->config->resolution.x / 10
				, g_engine->config->resolution.y / 10);
	draw_ath_texture(g_engine->player->inventory->ammo, pos, size);
}

/*
** Draw les trois parties du HUD du casque
*/

void		draw_hud_helmet(void)
{
	t_vector		size_hud;

	size_hud = create_vector(g_engine->config->resolution.x / 2.6
			, g_engine->config->resolution.y / 3.8);
	draw_hlmt_texture(13
			, create_vector(0, 0)
			, create_vector(g_engine->config->resolution.x
			, g_engine->config->resolution.y / 9));
	draw_hlmt_texture(14
			, create_vector(0
			, g_engine->config->resolution.y / 1.35)
			, size_hud);
	draw_hlmt_texture(15
			, create_vector(g_engine->config->resolution.x / 1.6
			, g_engine->config->resolution.y / 1.35)
			, size_hud);
}

/*
** Algo pour animation de mise en place du casque
*/

void		put_on_the_helmet(void)
{
	t_vector		coord;
	t_vector		size;

	coord = create_vector(0, 0);
	size = create_vector(g_engine->config->resolution.x
		, g_engine->config->resolution.y);
	if (g_engine->bonus->helmet->id_part_helmet != 12)
	{
		wait_time(45);
		draw_hlmt_texture(g_engine->bonus->helmet->id_part_helmet
			, coord, size);
		g_engine->bonus->helmet->id_part_helmet += 1;
	}
	else
	{
		draw_ath_run();
		draw_hud_helmet();
		sound_put_on_helmet(g_engine->bonus->helmet);
		draw_shield_health();
		weapon();
		draw_number_ammo();
	}
}
