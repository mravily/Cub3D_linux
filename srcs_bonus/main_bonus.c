/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:57:48 by mravily           #+#    #+#             */
/*   Updated: 2020/10/22 16:55:55 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		do_save(void)
{
	if (g_engine->config->save == true)
	{
		raycasting();
		start_screen();
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
	if (g_engine->player->health != 0)
	{
		raycasting();
		if (g_engine->event->start == false)
			start_screen();
		else
			put_on_the_helmet();
	}
	else
	{
		clear_screen();
		game_over_screen();
	}
	render_screen();
}

/*
** Initialisation des structures bonus
*/

void			engine_bonus(void)
{
	int			width_welcome;
	int			height_welcome;
	t_bonus		*bonus;

	bonus = g_engine->bonus;
	width_welcome = g_engine->config->resolution.x;
	height_welcome = g_engine->config->resolution.y;
	bonus->floor_cast = malloc_floor_cast(g_engine->ray_cast);
	bonus->img_welc = malloc_img_welc(width_welcome, height_welcome);
	bonus->welcome = malloc_welcome_tex("./textures/xpm/WELCOME.xpm");
	bonus->game_over = malloc_welcome_tex("./textures/xpm/GAME_OVER.xpm");
	bonus->helmet = malloc_helmet();
	bonus->weapon = malloc_weapon();
}

int				main(int argc, char **argv)
{
	g_engine = malloc_engine("Cub3D (c)");
	open_appli();
	pre_check_file(argc, argv);
	parsing_cub(argv[1]);
	resize_appli();
	engine_bonus();
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
