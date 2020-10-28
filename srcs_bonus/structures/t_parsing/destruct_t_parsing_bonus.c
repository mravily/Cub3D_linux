/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct_t_parsing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 11:35:58 by mravily           #+#    #+#             */
/*   Updated: 2020/10/22 14:25:44 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Destructor de la structure t_parsing
*/

static void		destroy_parsing(t_parsing to_destroy)
{
	to_destroy.resolution = false;
	to_destroy.north = false;
	to_destroy.south = false;
	to_destroy.west = false;
	to_destroy.east = false;
	to_destroy.sprite = false;
	to_destroy.floor = false;
	to_destroy.ceiling = false;
	to_destroy.map = false;
	to_destroy.player = false;
}

void			free_parsing(t_parsing *to_free)
{
	destroy_parsing(*to_free);
	free(to_free);
}
