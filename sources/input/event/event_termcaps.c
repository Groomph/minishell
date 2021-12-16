/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_termcaps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:48:48 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/16 22:46:12 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "input.h"
#include <unistd.h>

void	history_up(t_vector *history, t_input *input)
{
	if (input->hist_i > 0 && history->arr[0])
	{
		input->hist_i--;
		input->tmp = history->arr[input->hist_i];
		refresh_display(input);
		input->i = input->tmp->size;
	}
}

void	history_down(t_vector *history, t_input *input)
{
	if (input->hist_i == history->size - 1)
	{
		input->hist_i++;
		input->tmp = input->in;
		refresh_display(input);
		input->i = input->tmp->size;
	}
	else if (input->hist_i < history->size)
	{
		input->hist_i++;
		input->tmp = history->arr[input->hist_i];
		refresh_display(input);
		input->i = input->tmp->size;
	}
}

void	move_left(t_vector *history, t_input *input)
{
	if (input->i > 0)
	{
		(void)history;
		input->i--;
		cursor_left(1);
	}
}

void	move_right(t_vector *history, t_input *input)
{
	if (input->i < input->tmp->size)
	{
		(void)history;
		input->i++;
		cursor_right(1);
	}
}

#include <stdio.h>

void	delete_char(t_vector *history, t_input *input)
{
	if (input->i < input->tmp->size)
	{
		(void)history;
		vecstr_delone(input->tmp, input->i, 1);
		refresh_deleted(input);
	/*
		if (input->i < input->tmp->size)
			write(1, &(input->tmp->arr[input->i]), input->tmp->size - input->i);
		write(1, " ", 1);
		cursor_left(input->tmp->size - input->i + 1);
		input->display_size--;
	*/
	}
}
