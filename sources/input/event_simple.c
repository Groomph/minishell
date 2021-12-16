/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_simple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 01:31:32 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/16 03:45:46 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "input.h"

void	insert_char(t_msh *msh, t_input *input, char c)
{
	if (!vecstr_insert(input->tmp, input->i, c))
		assert_malloc(msh, NULL);
	input->i++;
}
