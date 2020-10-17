/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_helmet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 19:35:36 by mravily           #+#    #+#             */
/*   Updated: 2020/10/12 12:16:28 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Initialisation des elements de la structure t_helmet
*/

t_helmet		create_helmet(t_engine *engine)
{
	t_helmet		result;
	int				i;
	char			**path_hlmt;

	path_hlmt = init_tab_path_helmet_tex();
	i = -1;
	while (++i < HELMET_PART)
		result.helmet_part[i] = create_hlmt_tex(engine
			, ft_strdup(path_hlmt[i]));
	ft_tab_free(path_hlmt);
	path_hlmt = init_tab_path_ath_tex();
	i = -1;
	while (++i < ATH_PART)
		result.ath_part[i] = create_hlmt_tex(engine, ft_strdup(path_hlmt[i]));
	ft_tab_free(path_hlmt);
	result.id_part_helmet = 0;
	result.put_helmet = 0;
	result.img_hlmt = malloc_img_hlmt(engine, engine->config->resolution.x
		, engine->config->resolution.y);
	return (result);
}

t_helmet		*malloc_helmet(t_engine *engine)
{
	t_helmet	*helmet;

	helmet = (t_helmet *)malloc(sizeof(t_helmet));
	if (helmet == NULL)
		return (NULL);
	*helmet = create_helmet(engine);
	return (helmet);
}
