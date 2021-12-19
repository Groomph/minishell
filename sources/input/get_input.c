/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 20:28:49 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/19 19:01:22 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "input.h"
#include "libft.h"
#include <unistd.h>

#include <stdio.h> //test

static void	print_line_int(char *line, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		printf("%u\n", (unsigned char)line[i]);
		i++;
	}
}

/*
static voidd	isplay_info_input(t_input *input)
{
	printf("\n\n");
	printf("in: %s\n", input->in->arr); 
	printf("tmp: %s\n", input->tmp->arr); 
	printf("cursor: %i\n", input->i); 
	printf("cursor hist: %i\n", input->hist_i); 
	printf("display: %i\n", input->display_size); 
}
*/

void	init_input(t_msh *msh, t_input *input)
{
	input->in = assert_gc(msh, vecstr_new(10), (void *)(void *)vecstr_clean);
	input->tmp = input->in;
	input->i = 0;
	input->hist_i = msh->history.size;
	input->display_size = 0;
}

void	readinput(t_msh *msh, t_input *input, char *prompt, int size)
{
	char	buf[6];

	init_input(msh, input);
	write(1, prompt, size);
	buf[0] = '\0';
	while (buf[0] != '\n')
	{
		size = 0;
		while (size == 0)
			size = assert_errno(msh, read(0, buf, 5));
		buf[size] = '\0';
		if (buf[0] != '\n')
			interpret_input(msh, input, buf);
	}
}

//	if (input2.tmp == input->tmp)

void	complete_input(t_msh *msh, t_input *input)
{
	t_input	input2;

	readinput(msh, &input2, "\n> ", 3);
	assert_bool(msh, vecstr_add(input->tmp, '\n'));
	assert_bool(msh, vecstr_concat(input->tmp, input2.tmp));
	if (!is_closed_quote(input->tmp->arr))
	{
		complete_input(msh, input);
	}
}

//if (input.tmp != input.in)
//		vecstr_clean(&(input.in));

char	*get_input(t_msh *msh)
{
	t_input	input;
	int		size;

	readinput(msh, &input, "minishell: ", 11);
	if (!is_closed_quote(input.tmp->arr))
		complete_input(msh, &input);
	add_to_history(msh, input.tmp);
	size = string_len(input.tmp->arr);
	printf("\n\ninput: %s§\nsize: %i\n\n", input.tmp->arr, size);
	print_line_int(input.tmp->arr, size);
	reset_terminal(msh);
	return (input.tmp->arr);
}
