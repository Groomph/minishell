/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 21:17:31 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/27 11:25:40 by rsanchez         ###   ########.fr       */
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

static BOOL	inter_newline(void)
{
	write(1, "\n", 1);
	return (FALSE);
}

static BOOL	eof_error(char *end)
{
	write(1, "Warning: here-doc delimited by end-of-file (wanted \"", 52);
	write(1, end, string_len(end));
	write(1, "\")\n", 3);
	return (TRUE);
}

static BOOL	creating_heredoc(t_msh *msh, int fd, char *end)
{
	char	*input;

	input = read_input(&(msh->readin), "> ", 2);
	assert_gc(msh, input, free);
	if (msh->readin.state == INTERRUPTED)
		return (inter_newline());
	if (msh->readin.state == EOT)
		return (eof_error(end));
	input = expand_heredoc(msh, input);
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
		input = expand_heredoc(msh, input);
		write(1, "\n", 1);
	}
	return (TRUE);
}

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

//gestion du <<
BOOL	create_heredoc(t_msh *msh, t_command *cmd)
{
	int		fd;
	char	*name;

	name = concat_heredoc_id(msh, cmd->id);
	fd = open(name, O_CREAT | O_TRUNC | O_WRONLY,
			S_IROTH | S_IRGRP | S_IRUSR | S_IWGRP | S_IWUSR);
	if (fd == -1)
	{
		perror("unable to open redirection file : ");
		return (FALSE);
	}
	if (!(creating_heredoc(msh, fd, cmd->origin)))
	{
		close(fd);
		return (FALSE);
	}
	cmd->origin = name;
	close(fd);
	return (TRUE);
}
