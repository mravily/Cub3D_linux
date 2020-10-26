/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:42:14 by mravily           #+#    #+#             */
/*   Updated: 2020/10/26 13:02:05 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool			check_argument(int nb, char *to_check, char *argv)
{
	size_t	i;
	int		diff;

	i = 0;
	if (nb == 1)
	{
		while (argv[i] != '.')
			i++;
	}
	diff = ft_strcmp(to_check, argv + i);
	if (diff != 0)
		return (false);
	else
		return (true);
}

/*
** Verication du formatage des path de textures
*/

bool			check_texture_path(char *path)
{
	size_t	i;
	int		diff;

	i = 0;
	if (path[0] != '.' && path[1] != '/')
		error_exit_cub(path, "Invalid texture path"
			, "Find this line in the .cub file");
	while (path[i])
		i++;
	diff = ft_strcmp(".xpm", path + i - 4);
	if (diff != 0)
		return (false);
	else
		return (true);
}

/*
** parsing des lines du fichier .cub
*/

static bool		check_if_well_formated(int id, char *char_allowed
	, char *line)
{
	int		i;

	i = 0;
	while (ft_strcmp_c(char_allowed, line[i]) == true)
		i++;
	if (line[i] != '\0')
		error_line(id, line);
	return (true);
}

static bool		get_place_line(char *line, int i)
{
	if ((line[i] == 'R'
		&& check_if_well_formated(0, " R0123456789", line) == true))
	{
		get_resolution(line + i + 1, g_engine->config);
		return (true);
	}
	else if (is_line_texture(line, i) == true
		|| is_line_floor_ceiling(line, i) == true)
	{
		dispatch(line, i);
		return (true);
	}
	else if (line[i] == '1')
	{
		get_map(line, g_engine->config);
		return (true);
	}
	return (false);
}

void			check_line(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (get_place_line(line, i) == true)
			return ;
		i++;
	}
	error_exit_cub(line, "line is incorrect or not well formatted"
		, "Find this line in .cub file");
}
