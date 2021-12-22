/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:47:34 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/22 18:31:29 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "read_input.h"
#include <stdio.h>
#include <termios.h>

void	clear_readinput(t_readin *readin)
{
	gc_purge(&(readin->gc));
	vector_purge(&(readin->history), (void *)(void *) vecstr_clear);
}

BOOL	init_readinput(t_readin *readin)
{
	if (tcgetattr(0, &(readin->term_config)) == -1)
	{
		perror("init read_input: ");
		return (FALSE);
	}
	if (!gc_init(&(readin->gc)))
	{
		perror("init read_input: ");
		return (FALSE);
	}
	if (!vector_init(&(readin->history), 10))
	{
		vector_purge(&(readin->history), (void *)(void *) vecstr_clear);
		perror("init read_input: ");
		return (FALSE);
	}
	readin->eol = 0;
	return (TRUE);
}

void	clear_input(t_input *input)
{
	if (input->in == input->focus)
	{
		free(input->in);
	}
	else
	{
		vecstr_clear(input->in);
		free(input->focus);
	}
}

BOOL	init_input(t_readin *readin, t_input *input)
{
	input->in = vecstr_new(10);
	if (!(input->in))
	{
		perror("read_input: unable to allocate memory: ");
		return (FALSE);
	}
	input->focus = input->in;
	input->i = 0;
	input->hist_i = readin->history.size;
	input->display_i = 0;
	input->display_size = 0;
	readin->eol = 0;
	if (!init_terminal(readin, input))
	{
		vecstr_clear(input->in);
		return (FALSE);
	}
	if (!init_signal())
	{
		vecstr_clear(input->in);
		reset_terminal(readin);
		return (FALSE);
	}
	return (TRUE);
}
