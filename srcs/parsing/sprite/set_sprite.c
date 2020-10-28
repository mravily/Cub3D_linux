/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 18:40:53 by mravily           #+#    #+#             */
/*   Updated: 2020/10/28 15:18:04 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Set des reglages du sprites et comptabilisation du nombres de sprites
*/

static void		set_sprite(t_config *config, t_vector index, int id)
{
	config->sprite[config->num_sprites].x = index.x + 0.5f;
	config->sprite[config->num_sprites].y = index.y + 0.5f;
	config->sprite[config->num_sprites].id_texture = id;
	config->num_sprites++;
}

/*
** Check si aucun espace n'est present autour du sprite
** et set des ses reglages
*/

void			check_and_set_sprite(t_config *config, char **map
	, t_vector index)
{
	check_around(map, index);
	if (map[(int)index.y][(int)index.x] == '2')
		set_sprite(config, index, SPRITE);
}
