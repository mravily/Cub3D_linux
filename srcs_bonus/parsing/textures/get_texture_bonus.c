/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 17:58:53 by mravily           #+#    #+#             */
/*   Updated: 2020/10/17 18:07:37 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** recuperation des textures et verification de formatage du path
*/

void			get_texture(int id, char *line)
{
	char	**tab;
	int		len_tab;

	tab = NULL;
	len_tab = 0;
	tab = ft_strsplit(line, ' ');
	while (tab[len_tab])
		len_tab++;
	if (len_tab > 1 || len_tab == 0)
		error_exit_cub(id == 5 ? "Sprite" : "Wall"
			, "Sprite or Wall path not well formatted"
			, "Find this line in the .cub file");
	if (check_texture_path(tab[0]) == false)
		error_exit_cub(line, "Texture path extension isn't a xpm"
			, "Find this line in the .cub file");
	texture_assignment(id, tab[0]);
	ft_tab_free(tab);
}
