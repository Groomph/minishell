/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 22:18:59 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/22 18:46:45 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "read_input.h"

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
		if (msh->readin.eol)
		{
			free(input);
			free(input2);
			exit_program(msh);
			return (NULL);
		}
		input = strjoin_free(input, "\n", TRUE, FALSE);
		if (!input || !input2)
		{
			if (input)
				free(input);
			if (input2)
				free(input2);
			return (NULL);
		}
		input = strjoin_free(input, input2, TRUE, TRUE);
		if (!input)
			return (NULL);
	}
	return (input);
}

char	*get_input(t_msh *msh)
{
	char	*input;

	input = read_input(&(msh->readin), "minishell: ", 11);
	if (msh->readin.eol)
	{
		if (input)
			free(input);
		exit_program(msh);
		return (NULL);
	}
	if (!input)
		return (NULL);
	input = complete_input(msh, input, NULL);
	add_history(&(msh->readin), input);
	gc_add(&(msh->gc), input, free);
	return (input);
}
