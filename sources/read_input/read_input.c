/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:43:40 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/22 18:43:10 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "read_input.h"
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

/*
static void	print_info(t_input *input)
{
	int		i;
	char	*line;

	i = 0;
	line = input->focus->arr;
	while (i < input->focus->size)
	{
		printf("%u ", (unsigned char)line[i]);
		i++;
	}
	printf("\n%s\n", line);
	printf("%d\n", input->focus->size);
}
*/

static BOOL	read_input_routine(t_readin *readin, t_input *input)
{
	char	buf[6];
	int		size;

	buf[0] = '\0';
	while (buf[0] != '\n')
	{
		size = 0;
		while (size == 0)
			size = read(0, buf, 5);
		buf[size] = '\0';
		if (buf[0] == '\n' || (buf[0] == 4 && ++readin->eol))
			break ;
		if (size <= 0)
			return (FALSE);
		if (!interpret_input(readin, input, buf, size))
			return (FALSE);
	}
	return (TRUE);
}

char	*send_input(t_readin *readin, t_input *input, BOOL check)
{
	char	*str;

	if (!check)
	{
		str = malloc(sizeof(char));
		if (str)
			str[0] = '\0';
	}
	else
		str = input->focus->arr;
	clear_input(input);
	reset_terminal(readin);
	reset_signal();
	write(1, "\n", 1);
	return (str);
}

//	print_info(&input);

char	*read_input(t_readin *readin, char *prompt, int size)
{
	t_input	input;
	BOOL	check;

	if (!init_input(readin, &input))
		return (NULL);
	if (prompt)
		write(1, prompt, size);
	check = read_input_routine(readin, &input);
	if (!check && errno != EINTR)
	{
		vecstr_clear(input.in);
		if (input.in != input.focus)
			vecstr_clear(input.focus);
		perror("read_input: error: ");
		reset_terminal(readin);
		reset_signal();
		return (NULL);
	}
	return (send_input(readin, &input, check));
}
