/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_chr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:34:08 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/13 19:51:52 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*string_chr(const char *str, char c)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)&(str[i]));
		i++;
	}
	return (NULL);
}
