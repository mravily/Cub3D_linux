/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:46:28 by mravily           #+#    #+#             */
/*   Updated: 2020/10/26 13:00:26 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Vérifie si le char présent dans la line sont uniquement ceux autoriser
*/

void		check_char_line(char *char_allowed, char **tab)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (tab[y])
	{
		while (ft_strcmp_c(char_allowed, tab[y][i]) == true)
			i++;
		if (tab[y][i] == '\0')
		{
			i = 0;
			y++;
		}
		else
			error_exit_cub(tab[y], "Resolution not well formatted"
				, "check resolution line in .cub file and fix it");
	}
}

void		catch_error_resolution(char **tab, char *line)
{
	if (ft_tab_len((void**)tab) <= 1 || ft_tab_len((void**)tab) > 2)
		error_resolution(0, line);
	check_char_line("0123456789", tab);
}

void		resize_resolution(double *width, double *height, int s_width
	, int s_height)
{
	if (*width < 480)
	{
		ft_putendl("Width resize to 480");
		*width = 480;
	}
	if (*width > s_width)
	{
		ft_putendl("Width resize to maximal width screen");
		*width = s_width;
	}
	if (*height < 360)
	{
		ft_putendl("Height resize to 360");
		*height = 360;
	}
	if (*height > s_height)
	{
		ft_putendl("Height resize to maximal height screen");
		*height = s_height;
	}
}

/*
** Set la resolution trouver dans le fichier .cub.
** si la resolution est inferieur a 480 et 360 resize a cette dimension
** si la resolution est superieur a l' ecran resize a la dimension max
*/

void		set_resolution(char **tab, double *width, double *height)
{
	int		s_width;
	int		s_height;
	char	*error;

	mlx_get_screen_size(g_engine->vars->mlx_ptr, &s_width, &s_height);
	*width = ft_atoi(tab[0]);
	*height = ft_atoi(tab[1]);
	if (*width == 0 || *height == 0)
	{
		error = (*width == 0) ? "width equal to 0" : "height equal to 0";
		error_resolution(2, error);
	}
	resize_resolution(width, height, s_width, s_height);
}

/*
** Recuperation de la resolution et resize en cas de resolution incorrect
*/

void		get_resolution(char *line, t_config *config)
{
	char	**tab;
	double	width;
	double	height;

	tab = ft_strsplit(line, ' ');
	catch_error_resolution(tab, line);
	set_resolution(tab, &width, &height);
	if (g_engine->parsing->resolution == false)
	{
		config->resolution = create_vector((int)width, (int)height);
		g_engine->parsing->resolution = true;
	}
	else
		error_resolution(1, line);
	ft_tab_free(tab);
}
