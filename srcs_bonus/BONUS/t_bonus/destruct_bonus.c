/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 23:38:53 by mravily           #+#    #+#             */
/*   Updated: 2020/10/10 15:43:18 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Free des elements de la structure t_bonus
*/

void		destroy_bonus(t_vars vars, t_bonus to_destroy)
{
	free_floor_cast(to_destroy.floor_cast);
	free_img_welc(&vars, to_destroy.img_welc);
	free_welcome_tex(&vars, to_destroy.welcome);
	free_welcome_tex(&vars, to_destroy.game_over);
	free_helmet(to_destroy.helmet);
	free_weapon(to_destroy.weapon);
}

/*
** Free de la structure t_bonus
*/

void		free_bonus(t_vars *vars, t_bonus *to_free)
{
	destroy_bonus(*vars, *to_free);
	free(to_free);
}
