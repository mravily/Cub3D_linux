/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_line_floor_ceiling.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 13:36:40 by mravily           #+#    #+#             */
/*   Updated: 2020/10/26 17:53:10 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool		is_floor_line(char *line, int i)
{
	if (i == 0)
		if ((line[0] == 'F' && line[i + 1] == ' '))
			return (true);
		else
			return (false);
	else if (line[i - 1] == ' ' && line[i] == 'F' && line[i + 1] == ' ')
		return (true);
	return (false);
}

bool		is_ceiling_line(char *line, int i)
{
	if (i == 0)
		if ((line[0] == 'C' && line[i + 1] == ' '))
			return (true);
		else
			return (false);
	else if (line[i - 1] == ' ' && line[i] == 'C' && line[i + 1] == ' ')
		return (true);
	return (false);
}

bool		is_line_floor_ceiling(char *line, int i)
{
	if (is_floor_line(line, i) == true || is_ceiling_line(line, i) == true)
		return (true);
	return (false);
}
