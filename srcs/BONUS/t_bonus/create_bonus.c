/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 23:35:11 by mravily           #+#    #+#             */
/*   Updated: 2020/10/10 15:48:18 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Initialisation des elements de la structure t_bonus
*/

t_bonus		create_bonus(void)
{
	t_bonus		bonus;

	bonus.floor_cast = NULL;
	bonus.welcome = NULL;
	bonus.game_over = NULL;
	bonus.img_welc = NULL;
	bonus.helmet = NULL;
	bonus.weapon = NULL;
	return (bonus);
}

/*
** Mallocage de la structure t_bonus
*/

t_bonus		*malloc_bonus(void)
{
	t_bonus		*bonus;

	bonus = (t_bonus *)malloc(sizeof(t_bonus));
	if (bonus == NULL)
		return (NULL);
	*bonus = create_bonus();
	return (bonus);
}
