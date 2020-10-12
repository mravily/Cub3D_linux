/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_appli.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 22:11:29 by mravily           #+#    #+#             */
/*   Updated: 2020/10/10 15:31:46 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_APPLI_H
# define CUB3D_APPLI_H

# include "cub3d.h"

void		create_windows(t_engine *engine);
void		clear_screen(t_engine *engine);
void		render_screen(t_engine *engine);
void		render_mini_map(t_engine *engine);
void		open_appli(t_engine *engine);
void		resize_appli(t_engine *engine);
void		appli_key_hook_pressed(t_engine *engine, int event
	, int (*funct)(int, void *), void *param);
void		appli_key_hook_release(t_engine *engine, int event
	, int (*funct)(int, void *), void *param);
void		application_add_exit_control(t_engine *engine, int event
	, int (*funct)(void *), void *param);
void		appli_update(t_engine *engine
	, int (*funct)(void *), void *param);
int			handle_key_pressed(int key, void *params);
int			handle_key_release(int key, void *params);
int			run_appli(t_engine *engine);

#endif
