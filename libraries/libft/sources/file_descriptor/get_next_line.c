/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:48:15 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/13 14:20:16 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int	isnl(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int	extractline(char **buffer, char **line, size_t nl, size_t len)
{
	if (len == 0)
	{
		if (*buffer)
		{
			*line = *buffer;
			*buffer = NULL;
			return (string_len(*line));
		}
		*line = malloc(1);
		if (!(*line))
			return (-1);
		**line = '\0';
		return (0);
	}
	*line = substr_free(*buffer, 0, nl, DONTFREE);
	if (!*line)
		return (-1);
	*buffer = substr_free(*buffer, nl + 1, 4096, DOFREE);
	if (!*buffer)
		return (-1);
	return (nl);
}

/*read not secured*/

int	get_next_line(int fd, char **buffer, char **line, BOOL *eof)
{
	char		tmpbuf[4097];
	size_t		len;
	int			nl;

	if (fd < 0 || read(fd, NULL, 0) < 0 || !line || !buffer)
		return (-1);
	len = 1;
	nl = isnl(*buffer);
	while (nl == -1 && len)
	{
		len = read(fd, tmpbuf, 4096);
		if (len > 0)
		{
			tmpbuf[len] = '\0';
			*buffer = strjoin_free(*buffer, tmpbuf,
					DOFREE, DONTFREE);
			if (!(*buffer))
				return (-1);
			nl = isnl(*buffer);
		}
		else if (eof)
			*eof = TRUE;
	}
	return (extractline(buffer, line, nl, len));
}

/*
int	get_next_line_lobby(int fd, char **buffer, char **line, BOOL *eof)
{
	int	size;

	size = get_next_line(fd, buffer, line, eof);
	if (size == -1)
	{
		if (*line)
		{
			free(*line);
			*line = NULL;
		}
		if (*buffer)
		{
			free(*buffer);
			*buffer = NULL;
		}
	}
	return (size);
}
*/
