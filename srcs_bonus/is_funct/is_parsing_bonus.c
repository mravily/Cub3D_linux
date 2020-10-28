/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 18:02:47 by mravily           #+#    #+#             */
/*   Updated: 2020/10/26 18:02:55 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool			is_resolution_line(char *line, int i)
{
	if (i == 0)
		if ((line[0] == 'R' && line[i + 1] == ' '))
			return (true);
		else
			return (false);
	else if (line[i - 1] == ' ' && line[i] == 'R' && line[i + 1] == ' ')
		return (true);
	return (false);
}

bool			is_map_line(char *line, int i)
{
	if (i == 0)
		if (line[0] == '1')
			return (true);
		else
			return (false);
	else if (line[i - 1] == ' ' && line[i] == '1')
		return (true);
	return (false);
}
