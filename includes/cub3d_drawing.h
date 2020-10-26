/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_drawing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 23:29:26 by mravily           #+#    #+#             */
/*   Updated: 2020/10/17 18:06:40 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_DRAWING_H
# define CUB3D_DRAWING_H

# include "cub3d_engine.h"
# include "cub3d_vector.h"
# include "cub3d_color.h"
# include "cub3d.h"

void	draw_rectangle(t_vector coord, t_vector size
	, t_color color);
void	draw_circle(t_vector coord, int radius
	, t_color color);
void	draw_line(t_vector start, t_vector end
	, t_color color);
void	my_mlx_pixel_put(int x, int y, t_color color);
void	my_mlx_pixel_put_int(int x, int y, int color);
void	draw_wall(int x, t_color color);
void	draw_texture_wall(t_config *config, int x);
void	draw_ceiling_and_floor(int x, float height);
void	draw_resize_tex_in_screen(t_texture *texture
	, t_vector coord, t_vector size);

#endif
