/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 20:28:49 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/16 21:44:52 by rsanchez         ###   ########.fr       */
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
/*
static void	display_info_input(t_input *input)
{
	printf("\n\n");
	printf("in: %s\n", input->in->arr); 
	printf("tmp: %s\n", input->tmp->arr); 
	printf("cursor: %i\n", input->i); 
	printf("cursor hist: %i\n", input->hist_i); 
	printf("display: %i\n", input->display_size); 
}
*/
void    init_input(t_msh *msh, t_input *input)
{
        int     i;

        i = 0;
        input->in = assert_malloc(msh, vecstr_new(10));
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
//		display_info_input(input);
	}
}

void	complete_input(t_msh *msh, t_input *input)
{
	t_input	input2;

	readinput(msh, &input2, "> ", 2);
	assert_str(msh, input->tmp, '\n');
	assert_bool(msh, vecstr_concat_clean(input->tmp, input2.tmp, TRUE));
	if (!is_closed_quote(input->tmp->arr))
	{
		complete_input(msh, input);
	}
}

char	*get_input(t_msh *msh)
{
	t_input	input;
	int	size;

	readinput(msh, &input, "minishell: ", 11);
	if (!is_closed_quote(input.tmp->arr))
	{
		complete_input(msh, &input);
	}
	assert_vector(msh, &(msh->history), input.tmp);
	size = string_len(input.tmp->arr);
	printf("\n\ninput: %s§\nsize: %i\n\n", input.tmp->arr, size);
	print_line_int(input.tmp->arr, size);
	if (input.tmp->arr[0] == 'e' && input.tmp->arr[1] == 'x'
			&& input.tmp->arr[2] == 'i' && input.tmp->arr[3] == 't') 
		exit_program(msh);
	return (input.tmp->arr);
}
