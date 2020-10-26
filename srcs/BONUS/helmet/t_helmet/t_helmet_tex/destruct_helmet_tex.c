/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct_helmet_tex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 22:45:06 by mravily           #+#    #+#             */
/*   Updated: 2020/10/22 13:12:03 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Free des pointeurs de t_helmet_tex
*/

void		destroy_helmet_tex(t_helmet_tex to_destroy)
{
	free(to_destroy.path);
	mlx_destroy_image(g_engine->vars->mlx_ptr, to_destroy.img);
	to_destroy.addr = NULL;
	to_destroy.width = -1;
	to_destroy.height = -1;
	to_destroy.bits_per_pixel = -1;
	to_destroy.line_length = -1;
	to_destroy.endian = -1;
}
