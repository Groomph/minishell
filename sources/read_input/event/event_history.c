/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_history.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:48:48 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/22 13:15:23 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "read_input.h"

BOOL	history_swapper(t_vector *history, t_input *input)
{
	t_vecstr	*tmp;
	int			old_i;
	int			old_size;

	old_i = input->display_i;
	old_size = input->display_size;
	if (input->focus != input->in)
		vecstr_clear(input->focus);
	tmp = history->arr[input->hist_i];
	input->focus = vecstr_duplicate(tmp);
	if (!(input->focus))
		return (FALSE);
	input->i = input->focus->size;
	input->display_size = get_display_size(input->focus->arr);
	input->display_i = input->display_size;
	refresh_display(input, old_i, old_size);
	return (TRUE);
}

BOOL	history_up(t_vector *history, t_input *input)
{
	if (input->hist_i > 0 && history->arr[0])
	{
		input->hist_i--;
		return (history_swapper(history, input));
	}
	return (TRUE);
}

BOOL	history_down(t_vector *history, t_input *input)
{
	int	old_i;
	int	old_size;

	if (input->hist_i == history->size - 1)
	{
		input->hist_i++;
		old_i = input->display_i;
		old_size = input->display_size;
		input->focus = input->in;
		input->i = input->focus->size;
		input->display_size = get_display_size(input->focus->arr);
		input->display_i = input->display_size;
		refresh_display(input, old_i, old_size);
	}
	else if (input->hist_i < history->size)
	{
		input->hist_i++;
		return (history_swapper(history, input));
	}
	return (TRUE);
}
