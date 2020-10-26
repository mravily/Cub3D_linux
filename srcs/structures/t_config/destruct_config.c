/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct_config.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 17:27:36 by mravily           #+#    #+#             */
/*   Updated: 2020/10/22 13:28:56 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Free et remise a zero des elements de t_config
*/

void		destroy_config(t_config to_destroy)
{
	int		i;

	free(to_destroy.title);
	i = -1;
	while (++i < NB_TEX)
		destroy_texture(to_destroy.texture[i]);
	i = -1;
	while (++i < NB_SP)
		destroy_sprite(to_destroy.sprite[i]);
	free_vector(&to_destroy.resolution);
	free_color(&to_destroy.floor_color);
	free_color(&to_destroy.ceiling_color);
	free_map(to_destroy.map);
	to_destroy.num_sprites = -1;
	to_destroy.sprite_order = NULL;
	to_destroy.floor_w = null;
	to_destroy.ceiling_w = null;
	to_destroy.wall_tex_x = -1;
	to_destroy.wall_tex_y = -1;
	to_destroy.wall_color = NULL;
	to_destroy.floor_color_tex = NULL;
	to_destroy.ceiling_color_tex = NULL;
}

/*
** Free de la map
*/

void		free_map(char **map)
{
	int		i;

	i = -1;
	while (map[++i] != NULL)
		free(map[i]);
	free(map);
}

/*
** Free de la structure t_config
*/

void		free_config(t_config *to_free)
{
	destroy_config(*to_free);
	free(to_free);
}
