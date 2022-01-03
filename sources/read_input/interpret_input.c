/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:00:03 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/24 16:57:36 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "read_input.h"
#include <errno.h>

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

static BOOL	return_error(t_readin *readin)
{
	readin->state = ERROR;
	return (FALSE);
}

static BOOL	interpret_char(t_readin *r, t_input *input, char *buf, int size)
{
	int	termcaps;

	buf[size] = '\0';
	if (buf[0] == 27)
	{
		termcaps = get_termcaps(buf);
		if (termcaps != -1)
		{
			if (!termcaps_f(termcaps, r, input))
				return (return_error(r));
		}
	}
	else if (buf[0] == 127)
		backspace(input);
	else if (buf[0] == '\t' || buf[0] == 31)
		return (TRUE);
	else
	{
		if (!insert_char(input, buf, size))
			return (return_error(r));
	}
	return (TRUE);
}

BOOL	interpret_input(t_readin *readin, t_input *input, char *buf, int size)
{
	if (size <= 0 && errno == EINTR)
		readin->state = INTERRUPTED;
	else if (size <= 0)
		return (return_error(readin));
	else if (buf[0] == '\n')
		readin->state = NEWLINE;
	else if (buf[0] == 4)
	{
		if (input->i == 0)
			readin->state = EOT;
	}
	else
		return (interpret_char(readin, input, buf, size));
	return (TRUE);
}
