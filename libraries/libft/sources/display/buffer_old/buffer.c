/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:32:47 by rsanchez          #+#    #+#             */
/*   Updated: 2021/09/10 21:18:10 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"

static t_buffer	g_buf;

int	print_buffer(int fd)
{
	write(fd, g_buf.str, g_buf.i);
	g_buf.totalsize += g_buf.i;
	g_buf.i = 0;
	return (g_buf.totalsize);
}

void	write_str_buffer(const char *str, int size)
{
	int	i2;

	i2 = 0;
	if (size < 0)
	{
		while (str[i2])
		{
			g_buf.str[g_buf.i++] = str[i2++];
			if (g_buf.i == BUFFER_SIZE)
				print_buffer(1);
		}
	}
	while (i2 < size)
	{
		g_buf.str[g_buf.i++] = str[i2++];
		if (g_buf.i == BUFFER_SIZE)
			print_buffer(1);
	}
}

void	write_char_buffer(char c, int nb)
{
	int	i2;

	i2 = 0;
	while (i2++ < nb)
	{
		g_buf.str[g_buf.i++] = c;
		if (g_buf.i == BUFFER_SIZE)
			print_buffer(1);
	}
}

void	init_buffer(void)
{
	g_buf.i = 0;
	g_buf.totalsize = 0;
}
