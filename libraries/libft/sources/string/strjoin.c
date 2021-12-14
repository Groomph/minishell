/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:27:47 by rsanchez          #+#    #+#             */
/*   Updated: 2021/10/22 18:19:33 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strjoin_free(char *str1, char *str2, BOOL freestr1, BOOL freestr2)
{
	char	*tmp;

	tmp = strjoin(str1, str2);
	if (str1 && freestr1)
		free(str1);
	if (str2 && freestr2)
		free(str2);
	return (tmp);
}

char	*strjoin(char *str1, char *str2)
{
	size_t	i;
	size_t	i2;
	char	*temp;

	i = string_len(str1);
	i2 = string_len(str2);
	temp = malloc(sizeof(char) * (i + i2 + 1));
	if (!temp)
		return (NULL);
	temp[i + i2] = '\0';
	while (i2 > 0)
	{
		i2--;
		temp[i + i2] = str2[i2];
	}
	while (i > 0)
	{
		i--;
		temp[i] = str1[i];
	}
	return (temp);
}
