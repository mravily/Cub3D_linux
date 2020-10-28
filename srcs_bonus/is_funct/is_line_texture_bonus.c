/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_line_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 13:35:55 by mravily           #+#    #+#             */
/*   Updated: 2020/10/26 17:00:40 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool		is_north_line(char *line, int i)
{
	if (i == 0)
		if ((line[0] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' '))
			return (true);
		else
			return (false);
	else if (line[i - 1] == ' ' && line[i] == 'N' && line[i + 1] == 'O'
			&& line[i + 2] == ' ')
		return (true);
	return (false);
}

static bool		is_south_line(char *line, int i)
{
	if (i == 0)
		if ((line[0] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' '))
			return (true);
		else
			return (false);
	else if (line[i - 1] == ' ' && line[i] == 'S' && line[i + 1] == 'O'
			&& line[i + 2] == ' ')
		return (true);
	return (false);
}

static bool		is_east_line(char *line, int i)
{
	if (i == 0)
		if ((line[0] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' '))
			return (true);
		else
			return (false);
	else if (line[i - 1] == ' ' && line[i] == 'E' && line[i + 1] == 'A'
			&& line[i + 2] == ' ')
		return (true);
	return (false);
}

static bool		is_west_line(char *line, int i)
{
	if (i == 0)
		if ((line[0] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' '))
			return (true);
		else
			return (false);
	else if (line[i - 1] == ' ' && line[i] == 'W' && line[i + 1] == 'E'
			&& line[i + 2] == ' ')
		return (true);
	return (false);
}

bool			is_line_texture(char *line, int i)
{
	if (is_north_line(line, i) == true || is_south_line(line, i) == true
		|| is_west_line(line, i) == true || is_east_line(line, i) == true
		|| is_sprite_line(line, i) == true)
		return (true);
	return (false);
}
