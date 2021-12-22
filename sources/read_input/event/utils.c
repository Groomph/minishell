/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:10:35 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/21 22:32:39 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_utf_dist(unsigned char *str, int i)
{
	int	i2;

	i--;
	if (str[i] <= 0x80)
		return (1);
	i2 = 1;
	while (str[i] < 0xC0)
	{
		i--;
		i2++;
	}
	return (i2);
}

int	get_utf_size(unsigned char c)
{
	if (c <= 0x80)
		return (1);
	if (c < 0xE0)
		return (2);
	if (c < 0xF0)
		return (3);
	if (c < 0xF8)
		return (4);
	return (100);
}

int	get_display_size(unsigned char *str)
{
	int	i;
	int	display_size;

	i = 0;
	display_size = 0;
	while (str[i])
	{
		i += get_utf_size(str[i]);
		display_size++;
	}
	return (display_size);
}
