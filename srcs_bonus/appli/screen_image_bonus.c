/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 21:49:12 by mravily           #+#    #+#             */
/*   Updated: 2020/10/17 18:23:36 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Creation des pointeurs et du bitmap de la fenetre
*/

void		create_windows(void)
{
	g_engine->vars->win_ptr = mlx_new_window(g_engine->vars->mlx_ptr
		, (int)(g_engine->config->resolution.x)
		, (int)(g_engine->config->resolution.y)
		, g_engine->config->title);
	if (g_engine->vars->win_ptr == NULL)
		error_exit_cub("g_engine->vars->win_ptr == NULL"
			, "Problem when creating the window"\
			, "Check your structure");
	init_image(g_engine->image
		, g_engine->config->resolution.x
		, g_engine->config->resolution.y);
}

void		clear_screen(void)
{
	size_t		i;
	size_t		j;

	mlx_clear_window(g_engine->vars->mlx_ptr, g_engine->vars->win_ptr);
	i = 0;
	while (i < g_engine->config->resolution.x)
	{
		j = 0;
		while (j < g_engine->config->resolution.y)
		{
			my_mlx_pixel_put(i, j, create_color(0, 0, 0));
			j++;
		}
		i++;
	}
}

void		render_screen(void)
{
	mlx_put_image_to_window(g_engine->vars->mlx_ptr
		, g_engine->vars->win_ptr, g_engine->image->img, 0, 0);
}
