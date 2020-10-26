/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 18:47:08 by mravily           #+#    #+#             */
/*   Updated: 2020/10/26 17:49:07 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Recupere les lignes des textures dans le fichier .cub
*/

static void			line_texture(char *line, int i)
{
	if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
	{
		get_texture(1, line + i + 2);
		return ;
	}
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
	{
		get_texture(2, line + i + 2);
		return ;
	}
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
	{
		get_texture(3, line + i + 2);
		return ;
	}
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
	{
		get_texture(4, line + i + 2);
		return ;
	}
	else if (line[i] == 'S' && line[i + 1] == ' ')
	{
		get_texture(5, line + i + 1);
		return ;
	}
}

/*
** Recupere le RGB ou le PATH pour le ceiling dans le fichier cub
*/

static void			line_ceiling(char *line, int i)
{
	if (g_engine->parsing->ceiling == false
		&& line[i] == 'C' && line[i + 1] == ' ')
	{
		g_engine->parsing->ceiling = true;
		get_color(7, line + i + 1);
		return ;
	}
	else
		error_exit_cub(line, "2 lines of ceiling in the .cub file"
			, "Find this second line and delete it from the .cub file");
}

/*
** Recupere le RGB ou le PATH pour le floor dans le fichier cub
*/

static void			line_floor(char *line, int i)
{
	if (g_engine->parsing->floor == false
		&& line[i] == 'F' && line[i + 1] == ' ')
	{
		g_engine->parsing->floor = true;
		get_color(6, line + i + 1);
		return ;
	}
	else
		error_exit_cub(line, "2 lines of floor in the .cub file"
			, "Find this second line and delete it from the .cub file");
}

/*
** Redirige vers les functions pour recuperer les path ou les RGB
*/

void				dispatch(char *line, int i)
{
	if (is_line_texture(line, i) == true)
		line_texture(line, i);
	else if (is_floor_line(line, i) == true)
		line_floor(line, i);
	else if (is_ceiling_line(line, i == true))
		line_ceiling(line, i);
}
