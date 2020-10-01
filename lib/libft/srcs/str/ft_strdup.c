/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:31:23 by mravily           #+#    #+#             */
/*   Updated: 2020/09/26 17:36:37 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char		*ft_strdup(char *s)
{
	size_t	i;
	size_t	len_s;
	char	*dup;

	i = 0;
	len_s = ft_strlen(s);
	if (!(dup = (char *)malloc(sizeof(char) * (len_s + 1))))
		return (NULL);
	while (i < len_s)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}