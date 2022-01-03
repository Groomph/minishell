/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 21:17:31 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/03 21:13:09 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "read_input.h"
#include "parsing.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

static BOOL	is_expandable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static char	*expand_heredoc(t_msh *msh, char *str, char *end)
{
	int			i;
	t_vecstr	*string;

	i = -1;
	if (!is_expandable(str) || str_comp(str, end) == 0)
		return (str);
	string = vecstr_newfromstr(str);
	assert_gc(msh, string, (void *)(void *)vecstr_clear);
	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && is_alphanum(str[i + 1]))
			i = expand_var(msh, string, i);
		else if (str[i] == '$' && str[i + 1] == '?')
			i = expand_exitstate(msh, string, i);
		else
			i++;
	}
	return (string->arr);
}

static BOOL	creating_heredoc(t_msh *msh, int fd, char *end, char *input)
{
	while (1)
	{
		input = read_input(&(msh->readin), "> ", 2);
		assert_gc(msh, input, free);
		if (msh->readin.state == EOT)
		{
			write(1, "Warning: here-doc delimited by", 30);
			write(1, "end-of-file (wanted \"", 21);
			write(1, end, string_len(end));
			write(1, "\")\n", 3);
			return (TRUE);
		}
		write(1, "\n", 1);
		if (msh->readin.state == INTERRUPTED)
			return (FALSE);
		input = expand_heredoc(msh, input, end);
		if (str_comp(input, end) == 0)
			break ;
		write(fd, input, string_len(input));
		write(fd, "\n", 1);
	}
	return (TRUE);
}

static char	*trim_delimiter(char *delim)
{
	int		i;
	char	quote;

	i = 0;
	quote = '\0';
	while (delim[i])
	{
		if (delim[i] == '"' || delim[i] == '\'')
		{
			if (quote == delim[i])
			{
				shift_left_erase(delim, i--, 1);
				quote = '\0';
			}
			else if (!quote)
			{
				quote = delim[i];
				shift_left_erase(delim, i--, 1);
			}
		}
		i++;
	}
	return (delim);
}

//gestion du <<
BOOL	create_heredoc(t_msh *msh, t_command *cmd)
{
	int			fd;
	char		*name;
	BOOL		state;
	static char	heredoc[] = ".heredoc\0";

	name = ft_calloc(20, sizeof(char));
	if (!name)
		return (FALSE);
	assert_gc(msh, name, free);
	mem_copy(name, heredoc, 8);
	utoa_base(cmd->id, &(name[8]), "0123456789", 10);
	fd = open(name, O_CREAT | O_TRUNC | O_WRONLY,
			S_IROTH | S_IRGRP | S_IRUSR | S_IWGRP | S_IWUSR);
	if (fd == -1)
	{
		perror("Unable to open redirection file");
		return (FALSE);
	}
	state = creating_heredoc(msh, fd, trim_delimiter(cmd->origin), NULL);
	close(fd);
	if (!state)
		return (FALSE);
	cmd->origin = name;
	return (TRUE);
}

/*
   static BOOL	creating_heredoc(t_msh *msh, int fd, char *end)
   {
   char	*input;

   input = read_input(&(msh->readin), "> ", 2);
   assert_gc(msh, input, free);
   if (msh->readin.state == INTERRUPTED)
   return (inter_newline());
   if (msh->readin.state == EOT)
   return (eof_error(end));
   input = expand_heredoc(msh, input, end);
   write(1, "\n", 1);
   while (str_comp(input, end) != 0)
   {
   write(fd, input, string_len(input));
   write(fd, "\n", 1);
   input = read_input(&(msh->readin), "> ", 2);
   assert_gc(msh, input, free);
   if (msh->readin.state == INTERRUPTED)
   return (inter_newline());
   if (msh->readin.state == EOT)
   return (eof_error(end));
   input = expand_heredoc(msh, input, end);
   write(1, "\n", 1);
   }
   return (TRUE);
   }
   */
/*
   static char	*concat_heredoc_id(t_msh *msh, int id)
   {
   static char	heredoc[] = ".heredoc\0";
   char		*name;

   name = ft_calloc(20, sizeof(char));
   if (!name)
   return (NULL);
   assert_gc(msh, name, free);
   mem_copy(name, heredoc, 8);
   utoa_base(id, &(name[8]), "0123456789", 10);
   return (name);
   }
   */
