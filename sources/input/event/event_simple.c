/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_simple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 01:31:32 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/17 13:32:58 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "input.h"
#include <unistd.h>

void	insert_char(t_msh *msh, t_input *input, char c)
{
	if (!vecstr_insert(input->tmp, input->i, c))
		assert_malloc(msh, NULL);
	write(1, &(input->tmp->arr[input->i]), input->tmp->size - input->i);
	cursor_left(input->tmp->size - input->i - 1);
	input->i++;
	input->display_size++;
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
