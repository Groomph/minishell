/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:10:12 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/14 17:13:21 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void	display_prompt(char *prompt, int size)
{
	if (prompt && size >= 0)
		write(1, prompt, size);
	else if (prompt)
		write(1, prompt, string_len(prompt));
}

static int	is_nl(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*read_input(char *prompt, int size)
{
	char	buf_tmp[1025];
	char	*buf;
	int		nl;

	display_prompt(prompt, size);
	buf = NULL;
	size = 1;
	nl = -1;
	while (size && nl == -1)
	{
		size = read(0, buf_tmp, 1024);
		if (size == -1)
		{
			free(buf);
			return (NULL);
		}
		buf_tmp[size] = '\0';
		buf = strjoin_free(buf, buf_tmp, TRUE, FALSE);
		nl = is_nl(buf);
	}
	if (nl > -1 && buf[nl + 1])
		buf = substr_free(buf, 0, nl + 1, TRUE);
	return (buf);
}
