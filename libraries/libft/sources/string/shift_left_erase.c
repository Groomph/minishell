/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_left_erase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:26:41 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/16 02:37:24 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	shift_rec(char *str, int i, int dist)
{
	str[i] = str[i + dist];
	if (str[i])
		return (shift_rec(str, i + 1, dist));
	return (i);
}

int	shift_left_erase(char *str, int i, int dist)
{
	int	size;

	if (!str || i < 0 || dist <= 0)
		return (-1);
	size = string_len(str);
	if (i >= size)
		return (size);
	if (i + dist > size)
		dist = size - i;
	return (shift_rec(str, i, dist));
}
