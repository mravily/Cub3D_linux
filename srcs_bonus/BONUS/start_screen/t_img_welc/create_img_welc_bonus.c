/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img_welc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 22:14:03 by mravily           #+#    #+#             */
/*   Updated: 2020/10/17 18:34:27 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Creation des pointeurs et bitmap de l'image pour le start screen
*/

t_img_welc		create_img_welc(int width, int height)
{
	t_img_welc	img_welc;

	img_welc.width = width;
	img_welc.height = height;
	img_welc.addr = NULL;
	img_welc.addr = mlx_get_data_addr(g_engine->image->img
		, &(img_welc.bits_per_pixel)
		, &(img_welc.line_length)
		, &(img_welc.endian));
	if (img_welc.addr == NULL)
		error_exit_cub("g_engine->img_welc->addr == NULL"
			, "Problem when creating data address", "Check your structure");
	return (img_welc);
}

/*
** Mallocage de l'image pour le start screen
*/

t_img_welc		*malloc_img_welc(int width, int height)
{
	t_img_welc	*img_welc;

	img_welc = (t_img_welc *)malloc(sizeof(t_img_welc));
	if (img_welc == NULL)
		return (NULL);
	*img_welc = create_img_welc(width, height);
	return (img_welc);
}
