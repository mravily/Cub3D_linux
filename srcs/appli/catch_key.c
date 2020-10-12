/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 17:33:44 by mravily           #+#    #+#             */
/*   Updated: 2020/10/12 11:08:28 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Catch les event clavier de touche presser
*/

void			appli_key_hook_pressed(t_engine *engine, int event
	, int (*funct)(int, void *), void *param)
{
	mlx_hook(engine->vars->win_ptr, event, KEYPRESSMASK, funct, param);
}

/*
** Catch les event clavier de touche relacher
*/

void			appli_key_hook_release(t_engine *engine, int event
	, int (*funct)(int, void *), void *param)
{
	mlx_hook(engine->vars->win_ptr, event, KEYRELEASEMASK, funct, param);
}

/*
** Catch l'event quand l'utilisateur clique sur la croix rouge de la fenetre
*/

void			application_add_exit_control(t_engine *engine, int event
	, int (*funct)(void *), void *param)
{
	mlx_hook(engine->vars->win_ptr, event, DESTROYNOTIFYMASK, funct, param);
}

/*
** Reset la direction du player apres fermeture du screen de demarage
*/

void			re_set_dir_player(int key, t_player *player, t_event *event)
{
	if (key == RTN_KEY && event->start == false)
	{
		event->start = true;
		event->rotate_left = false;
		player->dir = player->start_dir;
		player->plane = player->start_plane;
		player->pos = player->start_pos;
	}
}
