/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 15:18:38 by mravily           #+#    #+#             */
/*   Updated: 2020/10/26 12:57:37 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			catch_error_color(int id, int len_tab, char *line)
{
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
