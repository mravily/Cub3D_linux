/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruc_weapon_tex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 13:24:40 by mravily           #+#    #+#             */
/*   Updated: 2020/10/21 16:54:29 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Free des pointeurs de t_weapon_tex
*/

void		destroy_weapon_tex(t_weapon_tex to_destroy)
{
	to_destroy.path = NULL;
	mlx_destroy_image(g_engine->vars->mlx_ptr, to_destroy.img);
	to_destroy.addr = NULL;
	to_destroy.width = -1;
	to_destroy.height = -1;
	to_destroy.bits_per_pixel = -1;
	to_destroy.line_length = -1;
	to_destroy.endian = -1;
}

/*
** Free de la structure t_weapon_tex
*/

void		free_weapon_tex(t_weapon_tex *to_free)
{
	free(to_free);
}
