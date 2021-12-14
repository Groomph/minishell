/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:32:47 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/10 17:40:10 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"
#include <unistd.h>

int	buffer_print(t_buff *buff, int fd)
{
	write(fd, buff->str, buff->i);
	buff->totalsize += buff->i;
	buff->i = 0;
	return (buff->totalsize);
}

void	buffer_str(t_buff *buff, const char *str, int size)
{
	int	i2;

	i2 = 0;
	if (size < 0)
	{
		while (str[i2])
		{
			buff->str[buff->i] = str[i2];
			buff->i++;
			i2++;
			if (buff->i == BUFFER_SIZE)
				buffer_print(buff, 1);
		}
	}
	while (i2 < size)
	{
		buff->str[buff->i] = str[i2];
		buff->i++;
		i2++;
		if (buff->i == BUFFER_SIZE)
			buffer_print(buff, 1);
	}
}

void	buffer_char(t_buff *buff, char c, int nb)
{
	int	i2;

	i2 = 0;
	while (i2 < nb)
	{
		buff->str[buff->i] = c;
		buff->i++;
		if (buff->i == BUFFER_SIZE)
			buffer_print(buff, 1);
		i2++;
	}
}

void	buffer_init(t_buff *buff)
{
	buff->i = 0;
	buff->totalsize = 0;
}
