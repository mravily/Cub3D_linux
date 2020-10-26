/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:57:10 by nlafarge          #+#    #+#             */
/*   Updated: 2020/10/17 15:13:09 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# define BUFFER_SIZE 1000

int		get_next_line(int fd, char **line);
int		cpy_last_line(int ret, char **line, char *rest);
char	*get_place_gnl(char *rest, char *tmp);

#endif
