/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_right_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:27:00 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/16 02:38:28 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
static void	shift_rec(char *str, int i, char c)
{
	if (c != '\0');
		shift_right_add(str, i + 1, str[i]);
	str[i] = c;
}

static int	shift_rec(char *str, int i, char c)
{
	if (!str[i])
	{
		str[i] = c;
		str[i + 1] = '\0';
		return (i + 1);
	}
	i = shift_right_add(str, str[i], i + 1);
	str[i] = c;
	return (i);
}
*/

#include "libft.h"

static int	shift_rec(char *str, int i, char c)
{
	char	tmp;

	if (!(str[i]))
	{
		str[i] = c;
		str[i + 1] = '\0';
		return (i + 1);
	}
	tmp = str[i];
	str[i] = c;
	return (shift_rec(str, i + 1, tmp));
}

int	shift_right_add(char *str, int i, char c)
{
	int	size;

	if (!str || i < 0)
		return (-1);
	size = string_len(str);
	if (i > size)
		return (size);
	return (shift_rec(str, i, c));
}
