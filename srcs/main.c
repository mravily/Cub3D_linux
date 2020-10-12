/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:57:48 by mravily           #+#    #+#             */
/*   Updated: 2020/10/10 15:28:28 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		do_save(t_engine *engine)
{
	if (engine->config->save == true)
	{
		render_game(engine);
		if (screen_shot(engine) == 0)
			error_exit_cub("Screen_shot", "During the screen_shot"
				, "Check Function");
		exit_screen_shot(engine);
	}
}

/*
** Function qui permettent d'afficher de le rendu du jeu a l'ecran
*/

void			render_game(t_engine *engine)
{
	if (engine->player->health != 0)
	{
		raycasting(engine);
		if (engine->event->start == false)
			start_screen(engine);
		else
			put_on_the_helmet(engine);
	}
	else
	{
		clear_screen(engine);
		game_over_screen(engine);
	}
	render_screen(engine);
}

/*
** Initialisation des structures bonus
*/

void			engine_bonus(t_engine *engine)
{
	int		width_welcome;
	int		height_welcome;

	width_welcome = engine->config->resolution.x;
	height_welcome = engine->config->resolution.y;
	engine->bonus->floor_cast = malloc_floor_cast(engine->ray_cast);
	engine->bonus->img_welc = malloc_img_welc(engine, width_welcome
		, height_welcome);
	engine->bonus->welcome = malloc_welcome_tex(engine
		, "./textures/xpm/WELCOME.xpm");
	engine->bonus->game_over = malloc_welcome_tex(engine
		, "./textures/xpm/GAME_OVER.xpm");
	engine->bonus->helmet = malloc_helmet(engine);
	engine->bonus->weapon = malloc_weapon(engine);
}

int				main(int argc, char **argv)
{

	t_engine 	*engine;

	engine = malloc_engine("Cub3D (c)");
	open_appli(engine);
	pre_check_file(engine, argc, argv);
	parsing_cub(argv[1], engine);
	resize_appli(engine);
	engine_bonus(engine);
	if (!(engine->sprite_cast->z_buffer = malloc(sizeof(float *)
		* engine->config->resolution.x + 1)))
			error_exit_cub("", "malloc z_buffer failed", "");
	appli_key_hook_pressed(engine, KEYPRESS, &handle_key_pressed, (void *)engine);
	appli_key_hook_release(engine, KEYRELEASE, &handle_key_release, (void *)engine);
	appli_update(engine, &update_player, (void *)engine);
	application_add_exit_control(engine, DESTROYNOTIFY, &exit_cub, (void *)engine);
	do_save(engine);
	run_appli(engine);
	
	return (0);
}
