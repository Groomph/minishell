/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:00:03 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/22 16:27:05 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "read_input.h"

#include <stdio.h>  //test

static const char	g_termcaps[5][5] = {
[ARROW_UP] = {27, '[', 'A', '\0', '\0'},
[ARROW_DOWN] = {27, '[', 'B', '\0', '\0'},
[ARROW_LEFT] = {27, '[', 'D', '\0', '\0'},
[ARROW_RIGHT] = {27, '[', 'C', '\0', '\0'},
[DELETE] = {27, '[', '3', '~', '\0'}
};

/*
const (static void	(*f[6]))(t_vector *history, t_input *input) =
{
	[ARROW_UP] = history_up,
	[ARROW_DOWN] = history_down,
	[ARROW_LEFT] = move_left,
	[ARROW_RIGHT] = move_right,
	[DELETE] = char_delete,
	NULL
};
*/

static BOOL	termcaps_f(int i, t_readin *readin, t_input *input)
{
	static BOOL	(*f[6])(t_vector *history, t_input *input) = {
	[ARROW_UP] = history_up,
	[ARROW_DOWN] = history_down,
	[ARROW_LEFT] = move_left,
	[ARROW_RIGHT] = move_right,
	[DELETE] = delete_char,
		NULL
	};

	return (f[i](&(readin->history), input));
}

int	get_termcaps(char *input)
{
	if (str_n_comp(input, g_termcaps[ARROW_UP], 3) == 0)
		return (ARROW_UP);
	if (str_n_comp(input, g_termcaps[ARROW_DOWN], 3) == 0)
		return (ARROW_DOWN);
	if (str_n_comp(input, g_termcaps[ARROW_LEFT], 3) == 0)
		return (ARROW_LEFT);
	if (str_n_comp(input, g_termcaps[ARROW_RIGHT], 3) == 0)
		return (ARROW_RIGHT);
	if (str_n_comp(input, g_termcaps[DELETE], 4) == 0)
		return (DELETE);
	return (-1);
}

BOOL	interpret_input(t_readin *readin, t_input *input, char *buf, int size)
{
	int	termcaps;

	if (buf[0] == 27)
	{
		termcaps = get_termcaps(buf);
		if (termcaps != -1)
		{
			if (!termcaps_f(termcaps, readin, input))
				return (FALSE);
		}
		else
			printf("UNKNOWN TERMCAPS\n");
	}
	else if (buf[0] == 127)
		backspace(input);
	else if (buf[0] != '\t' && buf[0] != 31)
	{
		if (!insert_char(input, buf, size))
			return (FALSE);
	}
	return (TRUE);
}
