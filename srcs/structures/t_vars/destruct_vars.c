/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct_vars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 15:11:37 by mravily           #+#    #+#             */
/*   Updated: 2020/10/10 16:13:14 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Function qui free
** - le pointeur de la mlx
** - le pointeur de la fenetre
*/

void	destroy_vars(t_vars to_destroy)
{
	mlx_destroy_window(to_destroy.mlx_ptr, to_destroy.win_ptr);
	free(to_destroy.mlx_ptr);
}

/*
** Function qui free la structure vars
*/

void	free_vars(t_vars *to_free)
{
	destroy_vars(*to_free);
	free(to_free);
}
