/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   how_many_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 15:26:51 by mravily           #+#    #+#             */
/*   Updated: 2020/10/26 17:54:31 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		how_many_char(char *str, char c)
{
	int		i;
	int		cmpt;

	cmpt = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			cmpt++;
		i++;
	}
	return (cmpt);
}
