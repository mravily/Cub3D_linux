/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 21:25:31 by mravily           #+#    #+#             */
/*   Updated: 2020/10/17 18:28:11 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Dessine le compteur de la shield bar
*/

void		compteur_shield(void)
{
	t_vector	pos;
	t_vector	size;

	pos = create_vector(g_engine->config->resolution.x / 3.6
			, g_engine->config->resolution.y / 1.11);
	size = create_vector(g_engine->config->resolution.x / 19
			, g_engine->config->resolution.y / 17);
	if (g_engine->player->shield == 0)
		draw_ath_texture(0, pos, size);
	if (g_engine->player->shield == 25)
		draw_ath_texture(25, pos, size);
	if (g_engine->player->shield == 50)
		draw_ath_texture(38, pos, size);
	if (g_engine->player->shield == 75)
		draw_ath_texture(39, pos, size);
	if (g_engine->player->shield == 100)
		draw_ath_texture(40, pos, size);
	if (g_engine->player->shield == 125)
		draw_ath_texture(41, pos, size);
	if (g_engine->player->shield == 150)
		draw_ath_texture(42, pos, size);
	if (g_engine->player->shield == 175)
		draw_ath_texture(43, pos, size);
	if (g_engine->player->shield == 200)
		draw_ath_texture(44, pos, size);
}

/*
** Dessine le compteur de la health bar
*/

void		compteur_health(void)
{
	t_vector	pos;
	t_vector	size;

	pos = create_vector(g_engine->config->resolution.x / 3.6
			, g_engine->config->resolution.y / 1.18);
	size = create_vector(g_engine->config->resolution.x / 19
			, g_engine->config->resolution.y / 17);
	if (g_engine->player->health == 0)
		draw_ath_texture(0, pos, size);
	if (g_engine->player->health == 25)
		draw_ath_texture(25, pos, size);
	if (g_engine->player->health == 50)
		draw_ath_texture(38, pos, size);
	if (g_engine->player->health == 75)
		draw_ath_texture(39, pos, size);
	if (g_engine->player->health == 100)
		draw_ath_texture(40, pos, size);
}

/*
** Dessine a l'ecran les differents pallier du shield blue
*/

void		draw_blue_shield(void)
{
	t_vector	coord_shield;
	t_vector	size;

	coord_shield = create_vector(g_engine->config->resolution.x / 5
			, g_engine->config->resolution.y / 1.14);
	size = create_vector(g_engine->config->resolution.x / 13
				, g_engine->config->resolution.y / 12);
	if (g_engine->player->shield == 125)
		draw_ath_texture(34, coord_shield, size);
	if (g_engine->player->shield == 150)
		draw_ath_texture(35, coord_shield, size);
	if (g_engine->player->shield == 175)
		draw_ath_texture(36, coord_shield, size);
	if (g_engine->player->shield == 200)
		draw_ath_texture(37, coord_shield, size);
}

/*
** Dessine a l'ecran les differents pallier du shield green
*/

void		draw_green_shield(void)
{
	t_vector	coord_shield;
	t_vector	size;

	coord_shield = create_vector(g_engine->config->resolution.x / 5
			, g_engine->config->resolution.y / 1.14);
	size = create_vector(g_engine->config->resolution.x / 13
			, g_engine->config->resolution.y / 12);
	if (g_engine->player->shield == 25)
		draw_ath_texture(30, coord_shield, size);
	if (g_engine->player->shield == 50)
		draw_ath_texture(31, coord_shield, size);
	if (g_engine->player->shield == 75)
		draw_ath_texture(32, coord_shield, size);
	if (g_engine->player->shield == 100)
		draw_ath_texture(33, coord_shield, size);
}

/*
** Dessine a l'ecran les differents pallier de la health bar
*/

void		draw_health(void)
{
	t_vector	coord_health;
	t_vector	size;

	coord_health = create_vector(g_engine->config->resolution.x / 4.9
			, g_engine->config->resolution.y / 1.24);
	size = create_vector(g_engine->config->resolution.x / 14
			, g_engine->config->resolution.y / 10);
	if (g_engine->player->health == 25)
		draw_ath_texture(26, coord_health, size);
	if (g_engine->player->health == 50)
		draw_ath_texture(27, coord_health, size);
	if (g_engine->player->health == 75)
		draw_ath_texture(28, coord_health, size);
	if (g_engine->player->health == 100)
		draw_ath_texture(29, coord_health, size);
}
