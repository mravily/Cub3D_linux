/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 19:06:42 by mravily           #+#    #+#             */
/*   Updated: 2020/10/26 18:03:09 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Verification si les color ne sont pas inf a 0 et sup a 255
*/

static void		check_if_rgb(int *rgb, char **tab, char *color)
{
	check_tab_line("0123456789", tab);
	rgb[0] = ft_atoi(tab[0]);
	if (rgb[0] < 0 || rgb[0] > 255)
		error_exit_cub(color, "Colour red badly formatted"
			, "Find this line in the .cub file");
	rgb[1] = ft_atoi(tab[1]);
	if (rgb[1] < 0 || rgb[1] > 255)
		error_exit_cub(color, "Colour green badly formatted"
			, "Find this line in the .cub file");
	rgb[2] = ft_atoi(tab[2]);
	if (rgb[2] < 0 || rgb[2] > 255)
		error_exit_cub(color, "Colour blue badly formatted"
			, "Find this line in the .cub file");
}

/*
** Verification du formatage color rgb
*/

static void		check_rgb_color(int id, char *color, t_config *config)
{
	char	**tab;
	int		rgb[3];

	tab = NULL;
	tab = ft_strsplit(color, ',');
	error_rgb(id, tab, color);
	check_if_rgb(rgb, tab, color);
	if (id == 6)
		config->floor_color = create_color(rgb[0], rgb[1], rgb[2]);
	else
		config->ceiling_color = create_color(rgb[0], rgb[1], rgb[2]);
	ft_tab_free(tab);
}

/*
** Set de la color du floor ou ceiling
*/

static void		get_rgb(int id, char *line_color, t_config *config)
{
	if (id == 6 && config->floor_w == null)
	{
		config->floor_w = rgb;
		check_rgb_color(id, line_color, config);
	}
	else if (id == 7 && config->ceiling_w == null)
	{
		config->ceiling_w = rgb;
		check_rgb_color(id, line_color, config);
	}
	else
		error_exit_cub(line_color, "Color (floor or ceiling) already attribute"
			, "only one of each element allowed in the .cub file");
}

/*
** Set du path du floor ou ceiling
*/

static void		get_path_color(int id, char *path_color)
{
	if (id == 6 && g_engine->config->floor_w == null)
	{
		if (check_texture_path(path_color) == true)
		{
			g_engine->config->floor_w = path;
			texture_assignment(id, path_color);
		}
		else
			error_path(id, path_color);
	}
	else if (id == 7 && g_engine->config->ceiling_w == null)
	{
		if (check_texture_path(path_color) == true)
		{
			g_engine->config->ceiling_w = path;
			texture_assignment(id, path_color);
		}
		else
			error_path(id, path_color);
	}
	else
		error_exit_cub(path_color, "Path (floor or ceiling) already attribute"
			, "only one of each element allowed in the .cub file");
}

/*
** Recuperation de la couleur en RGB ou path XPM
*/

void			get_color(int id, char *line)
{
	char		**tab;
	int			len_tab;
	t_config	*config;

	config = g_engine->config;
	len_tab = 0;
	tab = ft_strsplit(line, ' ');
	error_color(id, tab, line);
	if (tab[0][0] >= '0' && tab[0][0] <= '9')
		get_rgb(id, tab[0], config);
	else if (tab[0][0] == '.' && tab[0][1] == '/')
		get_path_color(id, tab[0]);
	else
		error_exit_cub(line
			, "Line not well formatted"
			, "Find this line in the .cub file");
	ft_tab_free(tab);
}
