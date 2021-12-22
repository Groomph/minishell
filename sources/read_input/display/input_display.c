/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:36:15 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/22 16:21:49 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_input.h"
#include <unistd.h>

void	refresh_from_position(t_input *input, int old_pos)
{
	int		str_right_part;
	int		display_dist;
	char	*str;

	str_right_part = input->focus->size - old_pos;
	str = &(input->focus->arr[old_pos]);
	write(1, str, str_right_part);
	display_dist = input->display_size - input->display_i;
	cursor_left(display_dist - 1);
}

void	refresh_deleted(t_input *input)
{
	int		str_right_part;
	int		display_dist;
	char	*str;
	int		i;

	str_right_part = input->focus->size - input->i;
	i = input->i;
	str = &(input->focus->arr[i]);
	write(1, str, str_right_part);
	write(1, " ", 1);
	display_dist = input->display_size - input->display_i;
	cursor_left(display_dist);
}

void	refresh_display(t_input *input, int old_i, int old_size)
{
	int	i;

	cursor_left(old_i);
	write(1, input->focus->arr, input->focus->size);
	i = old_size - input->display_size;
	if (i > 0)
	{
		while (i > 0)
		{
			write(1, "  ", 1);
			i--;
		}
		cursor_left(old_size - input->display_size);
	}
}
