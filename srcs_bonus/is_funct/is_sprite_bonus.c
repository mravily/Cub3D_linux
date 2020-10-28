/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 18:22:16 by mravily           #+#    #+#             */
/*   Updated: 2020/10/26 17:26:40 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool		is_sprite_line(char *line, int i)
{
	if (i == 0)
		if ((line[0] == 'S' && line[i + 1] == ' '))
			return (true);
		else
			return (false);
	else if (line[i - 1] == ' ' && line[i] == 'S' && line[i + 1] == ' ')
		return (true);
	return (false);
}

bool		is_sprite(char **map, t_vector index, char *list_sprite)
{
	if (ft_strcmp_c(list_sprite, map[(int)index.y][(int)index.x]) == true)
		return (true);
	return (false);
}
