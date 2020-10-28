/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_assignment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 15:05:44 by mravily           #+#    #+#             */
/*   Updated: 2020/10/28 15:19:41 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Verification et assignement du path de texture north et south
*/

static void		assign_north_south(int id, char *path)
{
	if (id == 1)
	{
		if (g_engine->config->texture[NORTH].path == NULL)
			g_engine->config->texture[NORTH] = create_texture(path);
		else
			error_exit_cub(path, "Two path north wall"
			, "Selecting one and deleting the other in the .cub file");
	}
	else if (id == 2)
	{
		if (g_engine->config->texture[SOUTH].path == NULL)
			g_engine->config->texture[SOUTH] = create_texture(path);
		else
			error_exit_cub(path, "Two path south wall"
			, "Selecting one and deleting the other in the .cub file");
	}
}

/*
** Verification et assignement du path de texture west et east
*/

static void		assign_west_east(int id, char *path)
{
	if (id == 3)
	{
		if (g_engine->config->texture[WEST].path == NULL)
			g_engine->config->texture[WEST] = create_texture(path);
		else
			error_exit_cub(path, "Two path west wall"
			, "Selecting one and deleting the other in the .cub file");
	}
	else if (id == 4)
	{
		if (g_engine->config->texture[EAST].path == NULL)
			g_engine->config->texture[EAST] = create_texture(path);
		else
			error_exit_cub(path, "Two path east wall"
			, "Selecting one and deleting the other in the .cub file");
	}
}

void			texture_assignment(int id, char *path)
{
	if (id == 1 || id == 2)
		assign_north_south(id, path);
	else if (id == 3 || id == 4)
		assign_west_east(id, path);
	else if (id == 5)
	{
		if (g_engine->config->texture[SPRITE].path == NULL)
			g_engine->config->texture[SPRITE] = create_texture(path);
		else
			error_exit_cub(path, "Two path for sprite"
			, "Selecting one and deleting the other in the .cub file");
	}
	else
		error_exit_cub(path, "Unrecognized ID"
			, "Check ID sent in texture assignement");
}
