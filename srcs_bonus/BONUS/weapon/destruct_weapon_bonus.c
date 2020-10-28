/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct_weapon.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 13:27:33 by mravily           #+#    #+#             */
/*   Updated: 2020/10/21 18:37:27 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Free des element de la structures t_weapon
*/

void		destroy_weapon(t_weapon to_destroy)
{
	int		i;

	i = 0;
	while (i < WEAPON_PART)
	{
		destroy_weapon_tex(to_destroy.weapon[i]);
		i++;
	}
}

/*
** Free de la structure t_weapon
*/

void		free_weapon(t_weapon *to_free)
{
	destroy_weapon(*to_free);
	free(to_free);
}
