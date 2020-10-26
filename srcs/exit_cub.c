/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 18:40:24 by mravily           #+#    #+#             */
/*   Updated: 2020/10/22 13:21:40 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_exit_cub(char *line, char *str, char *message)
{
	ft_putstr_fd("Error\n", 2);
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
	ft_putstr("Closing the Cub3D application\n");
	system("leaks cub3D | grep leaked");
	free_engine();
	exit(EXIT_SUCCESS);
}

int		exit_screen_shot(void)
{
	ft_putstr("A screen_shot was taken\n");
	free_engine();
	exit(EXIT_SUCCESS);
}
