/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_left_erase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:26:41 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/14 12:05:51 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	shift_rec(char *str, int i, int dist)
{
	str[i] = str[i + dist];
	if (str[i])
		return (shift_rec(str, i + 1, dist));
	return (i);
}

int	shift_left_erase(char *str, int i, int dist)
{
	int	i2;

	if (!str)
		return (-1);
	i2 = 0;
	while (i2 < dist && str[i + i2] != '\0')
		i2++;
	if (i2 < dist)
		dist = i2;
	if (dist == 0)
		return (i);
	return (shift_rec(str, i, dist));
}
