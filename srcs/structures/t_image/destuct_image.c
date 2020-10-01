/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destuct_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 17:40:56 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 15:55:53 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Mise a NULL et zero des variables avec free de la structure
*/

void		destroy_image(t_image to_destroy)
{
	to_destroy.img = NULL;
	to_destroy.addr = NULL;
	to_destroy.bits_per_pixel = 0;
	to_destroy.line_length = 0;
	to_destroy.endian = 0;
	(void)to_destroy;
}

/*
** Free de la structure t_image
*/

void		free_image(t_image *to_free)
{
	destroy_image(*to_free);
	free(to_free);
}
