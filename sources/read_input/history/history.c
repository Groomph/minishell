/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:09:38 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/21 20:41:36 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_input.h"
#include <stdio.h>

void	add_history(t_readin *readin, char *input)
{
	t_vecstr	*last;
	t_vector	*hist;
	t_vecstr	*new;

	hist = &(readin->history);
	if (hist->size > 0)
	{
		last = hist->arr[hist->size - 1];
		if (str_n_comp(last->arr, input, last->size + 1) == 0)
			return ;
	}
	new = vecstr_newfromstr(input);
	if (!new)
	{
		perror("add_readin: ");
		return ;
	}
	if (!vector_add(hist, new))
	{
		vecstr_clear(new);
		perror("add_readin: ");
		return ;
	}
}
