/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:00:03 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/16 03:29:19 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "input.h"

#include <stdio.h>

static const char 	g_termcaps[5][5] = {
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

static void	(*f_termcaps(int i))(t_vector *history, t_input *input)
{
	static void	(*f[6])(t_vector *history, t_input *input) =
	{
		[ARROW_UP] = history_up,
		[ARROW_DOWN] = history_down,
		[ARROW_LEFT] = move_left,
		[ARROW_RIGHT] = move_right,
		[DELETE] = char_delete,
		NULL
	};

	return (f[i]);
}

int	get_termcaps(char *input)
{
	if (str_n_comp(input, g_termcaps[ARROW_UP], 3) == 0)
	{
		printf("arrow up\n");
		return (ARROW_UP);
	}
	if (str_n_comp(input, g_termcaps[ARROW_DOWN], 3) == 0)
	{
		printf("arrow down\n");
		return (ARROW_DOWN);
	}
	if (str_n_comp(input, g_termcaps[ARROW_LEFT], 3) == 0)
	{
		printf("arrow left\n");
		return (ARROW_LEFT);
	}
	if (str_n_comp(input, g_termcaps[ARROW_RIGHT], 3) == 0)
	{
		printf("arrow right\n");
		return (ARROW_RIGHT);
	}
	if (str_n_comp(input, g_termcaps[DELETE], 4) == 0)
	{
		printf("delete\n");
		return (DELETE);
	}
	return (-1);
}

void	init_input(t_msh *msh, t_input *input)
{
	int	i;

	i = 0;
	input->in = assert_malloc(msh, vecstr_new(10));
	input->tmp = input->in;
	input->i = 0;
	input->hist_i = msh->history.size;
}

void	interpret_input(t_msh *msh, t_input *input)
{
	int	i;
	int	termcaps;

	(void)msh;
	i = 0;
	init_input(msh, input);
	while (input->input[i])
	{
		if (input->input[i] == 27)
		{
			termcaps = get_termcaps(&(input->input[i]));
			if (termcaps != -1)
				f_termcaps(termcaps)(&(msh->history), input);
			else
				printf("UNKNOWN TERMCAPS\n");
			i += 3;
			if (termcaps == DELETE)
				i++;
		}
		else
		{
			insert_char(msh, input, input->input[i]);
			i++;
		}
	}
}
