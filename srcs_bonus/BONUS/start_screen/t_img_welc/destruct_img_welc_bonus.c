/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct_img_welc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 22:15:47 by mravily           #+#    #+#             */
/*   Updated: 2020/10/12 12:18:15 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Free des pointeurs de t_img_welcome
*/

void		destroy_img_welc(t_vars vars, t_img_welc to_destroy)
{
	to_destroy.width = -1;
	to_destroy.height = -1;
	to_destroy.addr = NULL;
	to_destroy.bits_per_pixel = -1;
	to_destroy.line_length = -1;
	to_destroy.endian = -1;
	(void)vars;
}

/*
** Free de la structure t_img_welc
*/

void		free_img_welc(t_vars *vars, t_img_welc *to_free)
{
	destroy_img_welc(*vars, *to_free);
	free(to_free);
}
