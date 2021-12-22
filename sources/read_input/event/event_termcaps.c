/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_termcaps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:48:48 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/21 22:33:11 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "read_input.h"

#include <stdio.h>  //test

BOOL	move_left(t_vector *history, t_input *input)
{
	int	dist;

	if (input->i > 0)
	{
		(void)history;
		dist = get_utf_dist(input->focus->arr, input->i);
		input->i -= dist;
		cursor_left(1);
		input->display_i--;
	}
	return (TRUE);
}

BOOL	move_right(t_vector *history, t_input *input)
{
	int	dist;

	if (input->i < input->focus->size)
	{
		(void)history;
		dist = get_utf_size(input->focus->arr[input->i]);
		input->i += dist;
		cursor_right(1);
		input->display_i++;
	}
	return (TRUE);
}

BOOL	delete_char(t_vector *history, t_input *input)
{
	int	size;

	if (input->i < input->focus->size)
	{
		(void)history;
		size = get_utf_size(input->focus->arr[input->i]);
		vecstr_delone(input->focus, input->i, size);
		refresh_deleted(input);
		input->display_size--;
	}
	return (TRUE);
}
