/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 20:28:49 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/16 03:44:57 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "input.h"
#include "libft.h"
#include <unistd.h>

#include <stdio.h> //test

static void	print_line_int(char *line, int max) //fonction de test
{
	int	i;

	i = 0;
	while (i < max)
	{
		printf("%u\n", (unsigned char)line[i]);
		i++;
	}
}

void	complete_input(t_msh *msh, t_input *input)
{
	t_input	input2;

	input2.input = assert_gc(msh, read_input("> ", 2));
	interpret_input(msh, &input2);
	input->input = assert_gc(msh, strjoin(input->input, input2.input));
	if (!is_closed_quote(input->input))
	{
		complete_input(msh, input);
	}
}

char	*get_input(t_msh *msh)
{
	t_input	input;
	int	size;

	input.input = assert_gc(msh, read_input("minishell :", 11));
	interpret_input(msh, &input);
	if (!is_closed_quote(input.input))
	{
		complete_input(msh, &input);
	}
	assert_vector(msh, &(msh->history), input.tmp);
	size = string_len(input.tmp->arr);
	printf("\n\ninput: %s§\nsize: %i\n\n", input.tmp->arr, size);
	print_line_int(input.tmp->arr, size);
	if (input.input[0] == 'e' && input.input[1] == 'x'
			&& input.input[2] == 'i' && input.input[3] == 't') 
		exit_program(msh);
	return (input.tmp->arr);
}
