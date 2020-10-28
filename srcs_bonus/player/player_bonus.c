/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 16:02:22 by mravily           #+#    #+#             */
/*   Updated: 2020/10/17 18:09:22 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Calcale de la rotation a droite de la camera
*/

static void		rotate_right(t_player *player, float old_dir_x
	, float rot_speed, float old_plane_x)
{
	player->dir.x = player->dir.x * cos(rot_speed) - player->dir.y
		* sin(rot_speed);
	player->dir.y = old_dir_x * sin(rot_speed) + player->dir.y
		* cos(rot_speed);
	player->plane.x = player->plane.x * cos(rot_speed)
		- player->plane.y * sin(rot_speed);
	player->plane.y = old_plane_x * sin(rot_speed)
		+ player->plane.y * cos(rot_speed);
}

/*
** Calcule de la rotation a gauche de la camera
*/

static void		rotate_left(t_player *player, float old_dir_x
	, float rot_speed, float old_plane_x)
{
	player->dir.x = player->dir.x * cos(-rot_speed) - player->dir.y
		* sin(-rot_speed);
	player->dir.y = old_dir_x * sin(-rot_speed) + player->dir.y
		* cos(-rot_speed);
	player->plane.x = player->plane.x * cos(-rot_speed)
		- player->plane.y * sin(-rot_speed);
	player->plane.y = old_plane_x * sin(-rot_speed)
		+ player->plane.y * cos(-rot_speed);
}

/*
** Calcul de la rotation dans le raycasting
*/

static void		rotate_in_game(t_player *player, t_event *event)
{
	float		old_dir_x;
	float		old_plane_x;
	float		rot_speed;

	old_dir_x = player->dir.x;
	old_plane_x = player->plane.x;
	rot_speed = player->rot_speed;
	if (event->rotate_right == true)
		rotate_right(player, old_dir_x, rot_speed, old_plane_x);
	if (event->rotate_left == true)
		rotate_left(player, old_dir_x, rot_speed, old_plane_x);
}

/*
** Calcul du deplacement du joueur dans le raycasting
*/

static void		move_in_game(t_player *player, t_event *event
	, char **world_map)
{
	float		mov_speed;

	mov_speed = player->mov_speed;
	if ((event->forward == true && event->left == true)
		|| (event->forward == true && event->right == true)
		|| (event->backward == true && event->left == true)
		|| (event->backward == true && event->right == true))
		diagonal_movement(player, event, mov_speed, world_map);
	else
		simple_move(player, event, mov_speed, world_map);
}

int				update_player(void *params)
{
	t_engine	*engine;
	char		**world_map;

	engine = (t_engine *)params;
	world_map = g_engine->config->map;
	rotate_in_game(g_engine->player, g_engine->event);
	move_in_game(g_engine->player, g_engine->event, world_map);
	mlx_do_sync(g_engine->vars->mlx_ptr);
	render_game();
	return (0);
}
