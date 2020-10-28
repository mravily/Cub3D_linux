/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:57:48 by mravily           #+#    #+#             */
/*   Updated: 2020/10/27 15:44:03 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		do_save(void)
{
	if (g_engine->config->save == true)
	{
		raycasting();
		if (screen_shot() == 0)
			error_exit_cub("Screen_shot", "During the screen_shot"
				, "Check Function");
		exit_screen_shot();
	}
}

/*
** Function qui permettent d'afficher de le rendu du jeu a l'ecran
*/

void			render_game(void)
{
	clear_screen();
	raycasting();
	render_screen();
}

int				main(int argc, char **argv)
{
	g_engine = malloc_engine("Cub3D (c)");
	open_appli();
	pre_check_file(argc, argv);
	parsing_cub(argv[1]);
	resize_appli();
	if (!(g_engine->sprite_cast->z_buffer = malloc(sizeof(float *)
		* g_engine->config->resolution.x + 1)))
		error_exit_cub("", "malloc z_buffer failed", "");
	appli_key_hook_pressed(KEYPRESS, &handle_key_pressed
		, (void *)g_engine);
	appli_key_hook_release(KEYRELEASE, &handle_key_release
		, (void *)g_engine);
	application_add_exit_control(DESTROYNOTIFY, &exit_cub
		, (void *)g_engine);
	appli_update(&update_player, (void *)g_engine);
	do_save();
	run_appli();
	return (0);
}
