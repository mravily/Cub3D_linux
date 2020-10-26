/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct_helmet.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 22:56:43 by mravily           #+#    #+#             */
/*   Updated: 2020/10/22 13:11:05 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Free des element de la structures t_helmet
*/

void		destroy_helmet(t_helmet to_destroy)
{
	int		i;

	i = 0;
	while (i < HELMET_PART)
	{
		destroy_helmet_tex(to_destroy.helmet_part[i]);
		i++;
	}
	i = 0;
	while (i < ATH_PART)
	{
		destroy_helmet_tex(to_destroy.ath_part[i]);
		i++;
	}
	free_img_hlmt(to_destroy.img_hlmt);
}

/*
** Free de la structure t_helmet
*/

void		free_helmet(t_helmet *to_free)
{
	destroy_helmet(*to_free);
	free(to_free);
}
