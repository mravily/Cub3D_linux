/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_appli.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 22:11:29 by mravily           #+#    #+#             */
/*   Updated: 2020/10/17 18:13:24 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_APPLI_H
# define CUB3D_APPLI_H

# include "cub3d.h"

void		create_windows(void);
void		clear_screen(void);
void		render_screen(void);
void		render_mini_map(void);
void		open_appli(void);
void		resize_appli(void);
void		appli_key_hook_pressed(int event
	, int (*funct)(int, void *), void *param);
void		appli_key_hook_release(int event
	, int (*funct)(int, void *), void *param);
void		application_add_exit_control(int event
	, int (*funct)(void *), void *param);
void		appli_update(int (*funct)(void *), void *param);
int			handle_key_pressed(int key, void *params);
int			handle_key_release(int key, void *params);
int			run_appli(void);

#endif
