/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 20:28:49 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/14 12:40:42 by rsanchez         ###   ########.fr       */
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

static char	*complete_input(char *old_input)
{
	char	*new;

	new = read_input("> ", 2);
	new = strjoin_free(old_input, new, TRUE, TRUE);
	return (new);
}

char	*get_input(t_msh *msh)
{
	char	*input;
	int	size;

	input = read_input("minishell: ", 11);
	interpret_input(msh, input);
	while (!is_closed_quote(input))
		input = complete_input(input);
	size = string_len(input);
	printf("get_input\ninput: %s§\nsize: %i\n\n", input, size);
	assert_gc(msh, input);
	print_line_int(input, size);
	if (input[0] == 'e' && input[1] == 'x'
			&& input[2] == 'i' && input[3] == 't') 
		exit_program(msh);
	return (input);
}

