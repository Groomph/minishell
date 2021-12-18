/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:36:15 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/16 22:46:41 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include <unistd.h>

void	refresh_deleted(t_input *input)
{
	write(1, &(input->tmp->arr[input->i]), input->tmp->size - input->i);
	write(1, " ", 1);
	cursor_left(input->tmp->size - input->i + 1);
	input->display_size--;
}

void	refresh_display(t_input *input)
{
	int	i;

	cursor_left(input->i);
	write(1, input->tmp->arr, input->tmp->size);
	i = input->display_size - input->tmp->size;
	if (i > 0)
	{
		while (i > 0)
		{
			write(1, "  ", 1);
			i--;
		}
		cursor_left(input->display_size - input->tmp->size);
	}
	input->display_size = input->tmp->size;
}

/*
int	refresh_from_pos(int pos, char *str, int str_s, int display_s)
{
	int	printed;

	printed = str_s - pos;
	write(1, &(str[pos]), printed);
	display_s -= str_s;
	if (display_s > 0)
	{
		while (i < display_s)
		{
			write(1, "\0", 1);
			i++;
		}
		cursor_left(i);
	}
}

void	refresh_all_display(int cursor, char *str, int str_s, int display_s)
{
	int	i;

	i = 0;
	cursor_left(cursor);
	write(1, str, str_s);
	display_s -= str_s;
	if (display_s > 0)
	{
		while (i < display_s)
		{
			write(1, "\0", 1);
			i++;
		}
		cursor_left(i);
	}
	
}
*/
