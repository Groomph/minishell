/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_simple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 01:31:32 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/22 16:21:05 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "read_input.h"

static BOOL	insert_unicode(t_input *input, char *buf, int size)
{
	int	i;

	i = size;
	while (i > 0)
	{
		i--;
		if (!vecstr_insert(input->focus, input->i, buf[i]))
			return (FALSE);
	}
	input->display_size++;
	refresh_from_position(input, input->i);
	input->i += size;
	input->display_i++;
	return (TRUE);
}

static BOOL	insert_regular(t_input *input, char c)
{
	if (!vecstr_insert(input->focus, input->i, c))
		return (FALSE);
	input->display_size++;
	refresh_from_position(input, input->i);
	input->i++;
	input->display_i++;
	return (TRUE);
}

BOOL	insert_char(t_input *input, char *buf, int size)
{
	if (size == 1)
		return (insert_regular(input, buf[0]));
	else
		return (insert_unicode(input, buf, size));
}

void	backspace(t_input *input)
{
	int	size;

	if (input->i > 0)
	{
		size = get_utf_dist(input->focus->arr, input->i);
		input->i -= size;
		vecstr_delone(input->focus, input->i, size);
		cursor_left(1);
		input->display_i--;
		refresh_deleted(input);
		input->display_size--;
	}
}
