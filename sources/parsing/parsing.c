/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:22:00 by aldamien          #+#    #+#             */
/*   Updated: 2022/01/04 16:15:40 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "lexer.h"
#include "parsing.h"
#include <unistd.h>

BOOL	is_separator(char *token)
{
	if (!token)
		return (TRUE);
	if (token[0] == '|')
		return (TRUE);
	return (FALSE);
}

static BOOL	parse_separator(char **tokens, int i)
{
	if (i == 0)
	{
		write(1, "Error: starting command with pipe\n", 34);
		return (FALSE);
	}
	if (tokens[i][0] == '|' && tokens[i][1] == '\0')
	{
		if (tokens[i][0] == '|' && tokens[i + 1][0] != '|')
			return (TRUE);
		write(1, "Syntax error: near unexpected token \"", 37);
		write(1, tokens[i + 1], string_len(tokens[i + 1]));
		write(1, "\"\n", 2);
		return (FALSE);
	}
	write(1, "Syntax error: unknown operator \"", 32);
	write(1, tokens[i], string_len(tokens[i]));
	write(1, "\"\n", 2);
	return (FALSE);
}

int	parse_token(t_msh *msh, t_command *cmd, char **tokens)
{
	int	type;
	int	ret;

	type = fast_token_type(tokens[0][0]);
	ret = 0;
	if (type == TOK_OPERATOR)
		ret = parse_redirection(msh, cmd, tokens[0], tokens[1]);
	else
		ret = parse_word(msh, cmd, tokens[0]);
	if (ret <= 0)
		return (0);
	return (ret);
}

int	parse_new_command(t_msh *msh, t_vector *list, char **tokens, int id)
{
	int			i;
	t_command	*cmd;
	int			ret;

	i = 0;
	cmd = ft_calloc(1, sizeof(t_command));
	assert_gc(msh, cmd, free);
	if (!(vector_add(list, cmd)))
		return (0);
	cmd->args = vector_new(5);
	assert_gc(msh, cmd->args, (void *)(void *)vector_empty_clear);
	cmd->id = id;
	while (!(is_separator(tokens[i])))
	{
		ret = parse_token(msh, cmd, &(tokens[i]));
		if (ret <= 0)
			return (0);
		i += ret;
	}
	return (i);
}

int	parser(t_msh *msh, char **tokens, t_vector **list)
{
	int	i;
	int	id;
	int	ret;

	i = 0;
	id = 0;
	*list = vector_new(3);
	assert_gc(msh, *list, (void *)(void *)vector_empty_clear);
	while (tokens[i])
	{
		if (is_separator(tokens[i]))
			ret = parse_separator(tokens, i);
		else
		{
			ret = parse_new_command(msh, *list, &(tokens[i]), id);
			id++;
		}
		if (ret <= 0)
		{
			msh->exit_state = 2;
			return (id * -1);
		}
		i += ret;
	}
	return (id);
}
