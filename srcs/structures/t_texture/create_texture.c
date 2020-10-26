/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 10:10:31 by mravily           #+#    #+#             */
/*   Updated: 2020/10/22 13:27:04 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Initialisation a zero ou NULL du tableau de t_texture
*/

t_texture		init_texture(void)
{
	t_texture	result;

	result.path = NULL;
	result.img = NULL;
	result.width = 0;
	result.height = 0;
	result.color = NULL;
	result.bits_per_pixel = 0;
	result.line_length = 0;
	result.endian = 0;
	return (result);
}

/*
** Initialisation des variables de la struct t_texture
** - Pointeur vers l'image
** - Les bitmap de l'image stocker en int
*/

t_texture		create_texture(char *path)
{
	t_texture	texture;

	texture.path = path;
	if (!(texture.img = mlx_xpm_file_to_image(g_engine->vars->mlx_ptr
		, path, &(texture.width), &(texture.height))))
	{
		error_exit_cub(path
		, "during creation of xpm pointer for the texture, path invalid"
		, "Check if the image is present at this path.");
	}
	texture.color = (int *)mlx_get_data_addr(texture.img
		, &(texture.bits_per_pixel)
		, &(texture.line_length), &(texture.endian));
	return (texture);
}

/*
** Mallocage de la structure t_texture pour les walls
*/

t_texture		*malloc_texture(char *path)
{
	t_texture	*texture;

	texture = (t_texture *)malloc(sizeof(t_texture));
	if (texture == NULL)
		return (NULL);
	*texture = create_texture(path);
	return (texture);
}
