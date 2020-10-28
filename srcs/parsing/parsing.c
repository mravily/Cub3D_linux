/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:57:43 by mravily           #+#    #+#             */
/*   Updated: 2020/10/28 15:24:45 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** verification des arguments entrer lors de l'execution
*/

void			pre_check_file(int argc, char **argv)
{
	if (argc == 1)
		error_exit_cub("./Cub3D map.cub", "No maps provided"
			, "Provide a .cub file as argument");
	else if (argc == 2)
	{
		if (check_argument(1, ".cub", argv[1]) == false)
			error_exit_cub(argv[1], "Invalid map file extension"
				, "Only .cub files are accepted");
	}
	else if (argc == 3)
	{
		if (check_argument(1, ".cub", argv[1]) == false)
			error_exit_cub(argv[1], "Invalid map file extension"
				, "Only .cub files are accepted");
		if (check_argument(0, "-save", argv[2]) == false)
			error_exit_cub(argv[2], "third argument invalid"
				, "Only \"-save\" is allowed in third argument");
		else
			g_engine->config->save = true;
	}
	else if (argc > 3)
		error_exit_cub("", "Too many arguments", "Two argument max");
}

/*
** Verification si tout les textures sont initialisee
** si la position du joueur est indiquer
*/

static void		check_init_var_2(void)
{
	if (g_engine->config->texture[SOUTH].path == NULL)
		error_exit_cub("Texture[SOUTH]", "Provided path texture"
			, "Check .cub file");
	if (g_engine->config->texture[WEST].path == NULL)
		error_exit_cub("Texture[WEST]", "Provided path texture"
			, "Check .cub file");
	if (g_engine->config->texture[EAST].path == NULL)
		error_exit_cub("Texture[EAST]", "Provided path texture"
			, "Check .cub file");
	if (g_engine->config->texture[SPRITE].path == NULL)
		error_exit_cub("Texture[SPRITE]", "Provided path texture"
			, "Check .cub file");
}

static void		check_init_var(void)
{
	if (g_engine->parsing->resolution == 0)
		error_exit_cub("Resolution", "Resolution not indicated"
			, "Check .cub file");
	if (g_engine->config->resolution.y == 0)
		error_exit_cub("Resolution", "Resolution not well formatted"
			, "Check .cub file");
	if (g_engine->player->pos.x == 0)
		error_exit_cub("player->pos", "Player position not indicated in map"
			, "Check .cub file");
	if (g_engine->player->pos.y == 0)
		error_exit_cub("player->pos", "Player position not indicated in map"
			, "Check .cub file");
	if (g_engine->config->texture[NORTH].path == NULL)
		error_exit_cub("Texture[NORTH]", "Provided path texture"
			, "Check .cub file");
	check_init_var_2();
}

/*
** Verification de la ligne si elle contient uniquement les chars
** autoriser, puis ajout de la line tableau 2D
*/

void			get_map(char *line, t_config *config)
{
	check_line_map(line, config);
	ft_add_to_tab((void *)line, (void ***)&config->map);
}

/*
** parsing des information du fichier .cub
*/

void			parsing_cub(char *argv)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error_exit_cub("", "Impossible to open the file", "Check path file");
	ret = 1;
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		if (ft_strlen(line) != 0)
			check_line(line);
		free(line);
	}
	close(fd);
	check_map(g_engine->config, g_engine->player);
	check_init_var();
}
