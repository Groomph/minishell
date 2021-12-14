/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:00:03 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/14 17:11:56 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "input.h"

#include <stdio.h>

static char	g_termcaps[5][5] = {
	[ARROW_UP] = {27, '[', 'A', '\0', '\0'},
	[ARROW_DOWN] = {27, '[', 'B', '\0', '\0'},
	[ARROW_LEFT] = {27, '[', 'D', '\0', '\0'},
	[ARROW_RIGHT] = {27, '[', 'C', '\0', '\0'},
	[DELETE] = {27, '[', '3', '~', '\0'}
};
/*
static void	*g_termcaps_function[5] = {
	[ARROW_UP] = historic_up,
	[ARROW_DOWN] = historic_down,
	[ARROW_LEFT] = input_left,
	[ARROW_RIGHT] = input_right,
	[DELETE] = historic_up
}
*/
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

void	cut_input(char *input, int termcaps)
{
	if (termcaps < DELETE)
		shift_left_erase(input, 0, 4);
	else
		shift_left_erase(input, 0, 5);
}

void	interpret_input(t_msh *msh, char *input)
{
	int	i;
	int	termcaps;

	(void)msh;
	i = 0;
	while (input[i])
	{
		if (input[i] == 27)
		{
			termcaps = get_termcaps(&(input[i]));
			if (termcaps != -1)
				cut_input(&(input[i]), termcaps);
		}
		i++;
	}
}
