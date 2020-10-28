/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 17:33:44 by mravily           #+#    #+#             */
/*   Updated: 2020/10/28 15:16:25 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Catch les event clavier de touche presser
*/

void			appli_key_hook_pressed(int event
	, int (*funct)(int, void *), void *param)
{
	mlx_hook(g_engine->vars->win_ptr, event, KEYPRESSMASK, funct, param);
}

/*
** Catch les event clavier de touche relacher
*/

void			appli_key_hook_release(int event
	, int (*funct)(int, void *), void *param)
{
	mlx_hook(g_engine->vars->win_ptr, event, KEYRELEASEMASK, funct, param);
}

/*
** Catch l'event quand l'utilisateur clique sur la croix rouge de la fenetre
*/

void			application_add_exit_control(int event
	, int (*funct)(void *), void *param)
{
	mlx_hook(g_engine->vars->win_ptr, event, DESTROYNOTIFYMASK, funct, param);
}

/*
** Verifie si de nouvelle touche sont utiliser pour update l'image
*/

void			appli_update(int (*funct)(void *)
	, void *param)
{
	mlx_loop_hook(g_engine->vars->mlx_ptr, funct, param);
}
