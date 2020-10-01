/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:54:17 by mravily           #+#    #+#             */
/*   Updated: 2020/09/28 11:34:41 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*new_s;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(new_s = malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (NULL);
	ft_memcpy(new_s, s1, len_s1);
	ft_memcpy(new_s + len_s1, s2, len_s2);
	new_s[len_s1 + len_s2] = '\0';
	free(s1);
	return (new_s);
}

void		ft_place(char *rest, char *tmp)
{
	printf("test");
	free(rest);
	printf("test1");
	rest = tmp;
}
