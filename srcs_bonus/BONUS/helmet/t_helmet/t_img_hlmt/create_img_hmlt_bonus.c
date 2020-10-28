/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img_hmlt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 21:41:33 by mravily           #+#    #+#             */
/*   Updated: 2020/10/17 18:30:22 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img_hlmt		*malloc_img_hlmt(int width, int height)
{
	t_img_hlmt	*img_hlmt;

	img_hlmt = (t_img_hlmt *)malloc(sizeof(t_img_hlmt));
	if (img_hlmt == NULL)
		return (NULL);
	*img_hlmt = create_img_hlmt(width, height);
	return (img_hlmt);
}

t_img_hlmt		create_img_hlmt(int width, int height)
{
	t_img_hlmt	img_hlmt;

	img_hlmt.width = width;
	img_hlmt.height = height;
	img_hlmt.addr = NULL;
	img_hlmt.addr = mlx_get_data_addr(g_engine->image->img
		, &(img_hlmt.bits_per_pixel)
		, &(img_hlmt.line_length)
		, &(img_hlmt.endian));
	if (img_hlmt.addr == NULL)
		error_exit_cub("g_engine->img_hlmt->addr == NULL"
			, "Problem when creating data address", "Check your structure");
	return (img_hlmt);
}
