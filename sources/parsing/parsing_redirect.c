/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 17:02:26 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/01 12:58:51 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "lexer.h"
#include "parsing.h"
#include "redirect.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

static BOOL	is_valid_operator(char *token)
{
	if (token[0] == '<' || token[0] == '>')
	{
		if (token[1] == '\0')
			return (TRUE);
		if (token[0] == token[1] && token[2] == '\0')
			return (TRUE);
	}
	write(1, "Syntax error: unknown operator \"", 32);
	write(1, token, string_len(token));
	write(1, "\"\n", 2);
	return (FALSE);
}

static BOOL	is_valid_redirect(char *token, char *next)
{
	if (!(is_valid_operator(token)))
		return (FALSE);
	if (next && get_char_type(next[0]) != OPERATOR)
		return (TRUE);
	write(1, "Syntax error: unexpected next token \"", 32);
	if (next)
		write(1, next, string_len(next));
	else
		write(1, "newline", 7);
	write(1, "\"\n", 2);
	return (FALSE);
}

static BOOL	check_expansion(char *name_file, char *old_name)
{
	if (!name_file || name_file[0] == '\0')
	{
		write(1, old_name, string_len(old_name));
		write(1, ": ambiguous redirect\n", 21);
		return (FALSE);
	}
	return (TRUE);
}

static BOOL	create_out_file(char *name_file, char *old_name)
{
	int	fd;

	if (!check_expansion(name_file, old_name))
		return (FALSE);
	fd = open(name_file, O_CREAT | O_RDONLY,
			S_IROTH | S_IRGRP | S_IRUSR | S_IWGRP | S_IWUSR);
	if (fd == -1)
	{
		perror("Unable to create output redirection file");
		return (FALSE);
	}
	close(fd);
	return (TRUE);
}

int	parse_redirection(t_msh *msh, t_command *cmd, char *token, char *next)
{
	if (!(is_valid_redirect(token, next)))
		return (0);
	if (token[0] == '<')
	{
		cmd->red_in = red_origin(token);
		if (token[1])
		{
			cmd->origin = next;
			if (!create_heredoc(msh, cmd))
				return (0);
		}
		else
		{
			cmd->origin = trim_expand_var(msh, next);
			if (!check_expansion(cmd->origin, next))
				return (0);
		}
		return (2);
	}
	cmd->red_out = red_dest(token);
	cmd->dest = trim_expand_var(msh, next);
	if (!(create_out_file(cmd->dest, next)))
		return (0);
	return (2);
}
