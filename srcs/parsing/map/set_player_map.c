/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 17:20:09 by mravily           #+#    #+#             */
/*   Updated: 2020/10/22 16:01:50 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Set des reglages du player pour une orientation vers le NORD
*/

static void		set_north_player(t_player *player)
{
	player->dir = create_vector(0, -1);
	player->start_dir = player->dir;
	player->plane = create_vector(0.66, 0);
	player->start_plane = player->plane;
}

/*
** Set des reglages du player pour une orientation vers le SUD
*/

static void		set_south_player(t_player *player)
{
	player->dir = create_vector(0, 1);
	player->start_dir = player->dir;
	player->plane = create_vector(-0.66, 0);
	player->start_plane = player->plane;
}

/*
** Set des reglages du player pour une orientation vers l'EST
*/

static void		set_east_player(t_player *player)
{
	player->dir = create_vector(1, 0);
	player->start_dir = player->dir;
	player->plane = create_vector(0, 0.66);
	player->start_plane = player->plane;
}

/*
** Set des reglages du player pour une orientation vers l'OUEST
*/

static void		set_west_player(t_player *player)
{
	player->dir = create_vector(-1, 0);
	player->start_dir = player->dir;
	player->plane = create_vector(0, -0.66);
	player->start_plane = player->plane;
}

/*
** verification autour du player, que aucun espace n'est present
** et recuperation des coordonnee du player
*/

void			set_player(char **map, t_vector index, t_player *player)
{
	if (g_engine->parsing->player == false)
	{
		check_around(map, index);
		player->pos = create_vector(index.x + 0.5, index.y + 0.5);
		player->start_pos = player->pos;
		if (map[(int)index.y][(int)index.x] == 'N')
			set_north_player(player);
		else if (map[(int)index.y][(int)index.x] == 'S')
			set_south_player(player);
		else if (map[(int)index.y][(int)index.x] == 'E')
			set_east_player(player);
		else if (map[(int)index.y][(int)index.x] == 'W')
			set_west_player(player);
		g_engine->parsing->player = true;
	}
	else
		error_exit_cub(map[(int)index.y], "Two player start positions"
			, "Remove a player position on the map");
}
