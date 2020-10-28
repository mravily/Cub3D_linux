/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 21:54:27 by mravily           #+#    #+#             */
/*   Updated: 2020/10/26 16:24:45 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Mise a zero des variables de la struct avant free
*/

void	destroy_texture(t_texture to_destroy)
{
	to_destroy.path = NULL;
	if (to_destroy.img != NULL)
		mlx_destroy_image(g_engine->vars->mlx_ptr, to_destroy.img);
	to_destroy.color = NULL;
}

/*
** Free de la structure envoyer en parametre
*/

void	free_texture(t_texture *to_free)
{
	destroy_texture(*to_free);
	free(to_free);
}
