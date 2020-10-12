/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destuct_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 17:40:56 by mravily           #+#    #+#             */
/*   Updated: 2020/10/09 17:53:11 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Mise a NULL et zero des variables avec free de la structure
*/

void		destroy_image(t_vars vars, t_image to_destroy)
{
	mlx_destroy_image(vars.mlx_ptr, to_destroy.img);
	to_destroy.addr = NULL;
	to_destroy.bits_per_pixel = 0;
	to_destroy.line_length = 0;
	to_destroy.endian = 0;
	(void)to_destroy;
}

/*
** Free de la structure t_image
*/

void		free_image(t_vars *vars, t_image *to_free)
{
	destroy_image(*vars, *to_free);
	free(to_free);
}
