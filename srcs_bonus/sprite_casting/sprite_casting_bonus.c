/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_casting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 17:14:51 by mravily           #+#    #+#             */
/*   Updated: 2020/10/17 18:20:50 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void			check_get_item(t_config *config, t_player *player, int i)
{
	if (is_shield_sprite(config, player, i) == true
		|| is_medkit_sprite(config, player, i) == true
		|| is_backpack_sprite(config, player, i) == true
		|| is_weapon_sprite(config, player, i) == true)
	{
		config->sprite[i].active = false;
		get_item(player, config, i);
	}
}

/*
** Set la distance de chaque sprite par rapport au player
*/

static void			set_sprite_dist(t_config *config, t_player *player)
{
	int		i;

	i = 0;
	while (i < config->num_sprites)
	{
		config->sprite[i].sprite_dist = (player->pos.x
		- config->sprite[i].x)
			* (-config->sprite[i].x + player->pos.x)
			+ (player->pos.y - config->sprite[i].y)
			* (player->pos.y - config->sprite[i].y);
		if (config->sprite[i].sprite_dist < 0.16f
			&& config->sprite[i].active == true)
		{
			check_get_item(config, player, i);
		}
		else if (config->sprite[i].sprite_dist < 0.36f
			&& config->sprite[i].id_texture == COCADEMON)
			hit_by_enemy(player);
		i++;
	}
}

/*
** Fonction utiliser pour trier les sprites selon leur distance
** par rapport au joueur
*/

static void			short_sprites(t_config *config)
{
	int			i;
	int			j;

	j = config->num_sprites;
	while (j > 0)
	{
		i = 0;
		while (i < config->num_sprites - 1)
		{
			if (config->sprite[i].sprite_dist
				< config->sprite[i + 1].sprite_dist)
				swap_t_sprite(&config->sprite[i], &config->sprite[i + 1]);
			i++;
		}
		j--;
	}
}

/*
** Traduire la position du sprite par rapport a la camera
*/

static void			translate_sprite(int i)
{
	g_engine->sprite_cast->sprite_x = g_engine->config->sprite[i].x
		- g_engine->player->pos.x;
	g_engine->sprite_cast->sprite_y = g_engine->config->sprite[i].y
		- g_engine->player->pos.y;
	g_engine->sprite_cast->inv_det = 1.0 / (g_engine->player->plane.x
		* g_engine->player->dir.y
		- g_engine->player->dir.x
		* g_engine->player->plane.y);
	g_engine->sprite_cast->transform_x = g_engine->sprite_cast->inv_det
		* (g_engine->player->dir.y
		* g_engine->sprite_cast->sprite_x
		- g_engine->player->dir.x
		* g_engine->sprite_cast->sprite_y);
	g_engine->sprite_cast->transform_y = g_engine->sprite_cast->inv_det
		* (-g_engine->player->plane.y
		* g_engine->sprite_cast->sprite_x
		+ g_engine->player->plane.x
		* g_engine->sprite_cast->sprite_y);
	g_engine->sprite_cast->sprite_screen_x = (int)(
		(g_engine->config->resolution.x / 2)
		* (1 + g_engine->sprite_cast->transform_x
		/ g_engine->sprite_cast->transform_y));
}

/*
** Algo pour le sprite casting
*/

void				sprite_casting(void)
{
	int		i;

	set_sprite_dist(g_engine->config, g_engine->player);
	short_sprites(g_engine->config);
	i = 0;
	while (i < g_engine->config->num_sprites)
	{
		translate_sprite(i);
		calculate_sprite(g_engine->sprite_cast, g_engine->config, i);
		draw_sprite(i);
		i++;
	}
}
