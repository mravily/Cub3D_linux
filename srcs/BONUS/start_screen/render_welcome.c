/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_welcome.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 02:01:01 by mravily           #+#    #+#             */
/*   Updated: 2020/10/17 18:32:33 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			render_welcome(void)
{
	mlx_put_image_to_window(g_engine->vars->mlx_ptr, g_engine->vars->win_ptr
		, g_engine->bonus->img_welc->img, 0, 0);
}
