/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct_engine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 15:15:30 by mravily           #+#    #+#             */
/*   Updated: 2020/10/27 14:14:39 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Free des elements de la structure t_engine
*/

void		destroy_engine(t_engine to_destroy)
{
	free_parsing(to_destroy.parsing);
	free_ray_cast(to_destroy.ray_cast);
	free_sprite_cast(to_destroy.sprite_cast);
	free_player(to_destroy.player);
	free_event(to_destroy.event);
	free_config(to_destroy.config);
	free_image(to_destroy.vars, to_destroy.image);
	free_vars(to_destroy.vars);
}

/*
** Free de la structure t_engine
*/

void		free_engine(void)
{
	destroy_engine(*g_engine);
	free(g_engine);
}
