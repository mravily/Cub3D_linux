/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_basic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 23:37:04 by mravily           #+#    #+#             */
/*   Updated: 2020/10/22 13:24:40 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Allume le pixel a la coordonnee x et y avec la color envoyer en params
*/

void		my_mlx_pixel_put(int x, int y, t_color color)
{
	char	*dst;

	if (x < 0 || x >= g_engine->config->resolution.x
		|| y < 0 || y >= g_engine->config->resolution.y)
		return ;
	dst = g_engine->image->addr + (y * g_engine->image->line_length
		+ x * (g_engine->image->bits_per_pixel / 8));
	*(t_color *)dst = color;
}
