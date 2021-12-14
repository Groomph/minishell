/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:28:01 by rsanchez          #+#    #+#             */
/*   Updated: 2021/10/22 18:19:03 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*substr_free(char *str, size_t start, size_t len, BOOL freestr)
{
	char	*tmp;

	tmp = substr(str, start, len);
	if (str && freestr)
		free(str);
	return (tmp);
}

char	*substr(char *str, size_t start, size_t len)
{
	size_t	i;
	char	*temp;

	i = string_len(str);
	if (!str || i < start)
	{
		temp = malloc(sizeof(char));
		if (!temp)
			return (NULL);
		temp[0] = '\0';
		return (temp);
	}
	if (i < start + len)
		len = i - start;
	temp = malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (i < len)
	{
		temp[i] = str[start + i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
