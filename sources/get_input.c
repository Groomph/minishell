/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 22:18:59 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/03 17:59:36 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "read_input.h"
#include <unistd.h>

static BOOL	is_quote(char c)
{
	if (c == '\'' || c == '"')
		return (TRUE);
	return (FALSE);
}

static BOOL	is_closed_quote(char *input)
{
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	while (input && input[i])
	{
		if (!quote && is_quote(input[i]))
			quote = input[i];
		else if (quote && quote == input[i])
			quote = 0;
		i++;
	}
	if (quote)
		return (FALSE);
	return (TRUE);
}

static char	*complete_input(t_msh *msh, char *input, char *input2)
{
	while (!is_closed_quote(input))
	{
		input2 = read_input(&(msh->readin), "> ", 2);
		write(1, "\n", 1);
		assert_gc(msh, input2, free);
		if (msh->readin.state == EOT)
			exit_program(msh, 0);
		if (msh->readin.state == INTERRUPTED)
			return (NULL);
		input = strjoin(input, "\n");
		assert_gc(msh, input, free);
		input = strjoin(input, input2);
		assert_gc(msh, input, free);
	}
	return (input);
}

char	*get_input(t_msh *msh)
{
	char	*input;

	input = read_input(&(msh->readin), "\e[1;35mminishell: \e[0m", 22);
	assert_gc(msh, input, free);
	write(1, "\n", 1);
	if (msh->readin.state == EOT)
		exit_program(msh, 0);
	if (msh->readin.state == INTERRUPTED)
		return (NULL);
	input = complete_input(msh, input, NULL);
	if (input)
		add_history(&(msh->readin), input);
	return (input);
}
