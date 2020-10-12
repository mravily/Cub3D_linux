/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bundler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 14:58:08 by mravily           #+#    #+#             */
/*   Updated: 2020/10/10 16:35:31 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_exit_cub(char *line, char *str, char *message)
{
	ft_putstr_fd("Error:\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[\"", 2);
	ft_putstr_fd(line, 2);
	ft_putstr_fd("\"] <- ", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	exit(0);
}

int		exit_cub(void *param)
{
	t_engine *engine;

	engine = (t_engine *)param;
	ft_putstr("\nClosing the Cub3D application without error\n");
	free_engine(engine);
	exit(EXIT_SUCCESS);
}

int		exit_screen_shot(t_engine *engine)
{
	ft_putstr("A screen_shot was taken\n");
	free_engine(engine);
	exit(EXIT_SUCCESS);
}
