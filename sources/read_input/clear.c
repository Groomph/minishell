/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:47:34 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/24 16:15:15 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_input.h"
#include <stdlib.h>

void	clear_readinput(t_readin *readin)
{
	gc_purge(&(readin->gc));
	vector_purge(&(readin->history), (void *)(void *) vecstr_clear);
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
