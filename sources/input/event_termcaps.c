/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_termcaps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:48:48 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/16 03:31:56 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "input.h"

void	history_up(t_vector *history, t_input *input)
{
	if (input->hist_i > 0 && history->arr[0])
	{
		input->hist_i--;
		input->tmp = history->arr[input->hist_i];
		input->i = input->tmp->size;
	}
}

void	history_down(t_vector *history, t_input *input)
{
	if (input->hist_i == history->size - 1)
	{
		input->hist_i++;
		input->tmp = input->in;
		input->i = input->tmp->size;
	}
	else if (input->hist_i < history->size)
	{
		input->hist_i++;
		input->tmp = history->arr[input->hist_i];
		input->i = input->tmp->size;
	}
}

void	move_left(t_vector *history, t_input *input)
{
	(void)history;
	input->i--;
}

void	move_right(t_vector *history, t_input *input)
{
	(void)history;
	input->i++;
}

void	char_delete(t_vector *history, t_input *input)
{
	(void)history;
	vecstr_delone(input->tmp, input->i, 1);
}
