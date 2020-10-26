/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:54:17 by mravily           #+#    #+#             */
/*   Updated: 2020/10/17 15:12:39 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*get_place_gnl(char *rest, char *tmp)
{
	free(rest);
	rest = ft_strdup(tmp);
	free(tmp);
	return (rest);
}
