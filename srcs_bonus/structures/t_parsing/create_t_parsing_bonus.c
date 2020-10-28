/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_t_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 11:24:39 by mravily           #+#    #+#             */
/*   Updated: 2020/10/22 14:26:24 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_parsing		create_parsing(void)
{
	t_parsing	result;

	result.resolution = false;
	result.north = false;
	result.south = false;
	result.west = false;
	result.east = false;
	result.sprite = false;
	result.floor = false;
	result.ceiling = false;
	result.map = false;
	result.player = false;
	return (result);
}

t_parsing		*malloc_parsing(void)
{
	t_parsing		*parsing;

	parsing = (t_parsing*)malloc(sizeof(t_parsing));
	if (parsing == NULL)
		return (NULL);
	*parsing = create_parsing();
	return (parsing);
}
