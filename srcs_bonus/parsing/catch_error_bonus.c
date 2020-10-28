/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 15:18:38 by mravily           #+#    #+#             */
/*   Updated: 2020/10/26 18:01:26 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			error_path(int id, char *line)
{
	if (id == 6)
		error_exit_cub(line
			, "Floor line not well formatted"
			, "Find this line in the .cub file");
	if (id == 7)
		error_exit_cub(line
			, "Ceiling line not well formatted"
			, "Find this line in the .cub file");
}

void			error_rgb(int id, char **tab, char *color)
{
	int		len_tab;
	int		cmpt;

	cmpt = how_many_char(color, ',');
	len_tab = ft_tab_len((void **)tab);
	if ((cmpt < 2 || cmpt > 2
		|| len_tab < 3 || len_tab > 3) && id == 0)
		error_exit_cub(color, "Invalid RGB floor color"
			, "Find this line in the .cub file");
	if ((cmpt < 2 || cmpt > 2
		|| len_tab < 3 || len_tab > 3) && id == 1)
		error_exit_cub(color, "Invalid RGB ceiling color"
			, "Find this line in the .cub file");
	if ((cmpt < 2 || cmpt > 2
		|| len_tab < 3 || len_tab > 3) && id == 6)
		error_exit_cub(color
			, "Floor line not well formatted"
			, "Find this line in the .cub file");
	if ((cmpt < 2 || cmpt > 2
		|| len_tab < 3 || len_tab > 3) && id == 7)
		error_exit_cub(color
			, "Ceiling line not well formatted"
			, "Find this line in the .cub file");
}

void			error_color(int id, char **tab, char *line)
{
	int		len_tab;

	len_tab = ft_tab_len((void **)tab);
	if ((len_tab < 1 || len_tab > 1) && id == 6)
		error_exit_cub(line
			, "Floor line not well formatted"
			, "Find this line in the .cub file");
	if ((len_tab < 1 || len_tab > 1) && id == 7)
		error_exit_cub(line
			, "Ceiling line not well formatted"
			, "Find this line in the .cub file");
	if ((len_tab > 1 || len_tab == 0) && id == 0)
		error_exit_cub(line, "Invalid floor color"
			, "Find this line in the .cub file");
	if ((len_tab > 1 || len_tab == 0) && id == 1)
		error_exit_cub(line, "Invalid ceiling color"
			, "Find this line in the .cub file");
}

void			error_resolution(int id, char *line)
{
	if (id == 0)
		error_exit_cub(line, "Resolution line not well formatted"
			, "The resolution must be indicated as folllow : R width height");
	if (id == 1)
		error_exit_cub(line, "2 lines of resolution in the .cub file"
			, "Find this second line and delete it from the .cub file");
	if (id == 2)
		error_exit_cub(line, "Width or height equal to 0"
			, "Resolution must be superior to 0");
}

void			error_line(int id, char *line)
{
	if (id == 0)
		error_resolution(0, line);
}
