/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_simple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 01:31:32 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/20 16:57:36 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "input.h"
#include <unistd.h>

void	insert_unicode(t_msh *msh, t_input *input, char *buf, int size)
{
	(void)msh;
	(void)input;
	(void)buf;
	size++;
	return ;
}

void	insert_regular(t_msh *msh, t_input *input, char c)
{
	assert_bool(msh, vecstr_insert(input->tmp, input->i, c));
	write(1, &(input->tmp->arr[input->i]), input->tmp->size - input->i);
	cursor_left(input->tmp->size - input->i - 1);
	input->i++;
	input->display_size++;
}

void	insert_char(t_msh *msh, t_input *input, char *buf, int size)
{
	if (size == 1)
		insert_regular(msh, input, buf[0]);
	else
		insert_unicode(msh, input, buf, size);
}

void	backspace(t_input *input)
{
	if (input->i > 0)
	{
		input->i--;
		cursor_left(1);
		vecstr_delone(input->tmp, input->i, 1);
		refresh_deleted(input);
	}
}

/*
		write(1, &(input->tmp->arr[input->i]), input->tmp->size - input->i);
                write(1, " ", 1);
                cursor_left(input->tmp->size - input->i + 1);
                input->display_size--;
*/
