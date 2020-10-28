/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_appli.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 17:31:06 by mravily           #+#    #+#             */
/*   Updated: 2020/10/17 18:25:30 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** initialisation de la minilibx et des connexions avec le systeme graphique
*/

void		open_appli(void)
{
	g_engine->vars->mlx_ptr = mlx_init();
	if (g_engine->vars->mlx_ptr == NULL)
		error_exit_cub("g_engine->vars->mlx_ptr == NULL"
			, "Problem when launching the MLX", "Check your structure");
	create_windows();
}

void		resize_appli(void)
{
	mlx_destroy_image(g_engine->vars->mlx_ptr, g_engine->image->img);
	mlx_destroy_window(g_engine->vars->mlx_ptr, g_engine->vars->win_ptr);
	create_windows();
}

void		render_appli(void)
{
	mlx_put_image_to_window(g_engine->vars->mlx_ptr
		, g_engine->vars->win_ptr, g_engine->image->img, 0, 0);
}

int			run_appli(void)
{
	mlx_loop(g_engine->vars->mlx_ptr);
	return (0);
}
