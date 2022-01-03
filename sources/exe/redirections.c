/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 02:25:25 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/02 23:07:22 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include <unistd.h>
#include <stdio.h>

void	connect_pipe(t_command **cmds, int i, int len)
{
	t_command	*cmd;
	int			fd_in;

	cmd = cmds[i];
	close(cmd->pipe[0]);
	if (i < len - 1)
	{
		if (dup2(cmd->pipe[1], STDOUT_FILENO) == -1)
			perror("Unable to dup2 stdout");
	}
	close(cmd->pipe[1]);
	if (i > 0)
	{
		fd_in = cmds[i - 1]->pipe[0];
		if (dup2(fd_in, STDIN_FILENO) == -1)
			perror("Unable to dup2 stdin pipe");
		close(fd_in);
	}
}

BOOL	file_redirections(t_command *cmd)
{
	if (cmd->dest)
		cmd->red_out(cmd->dest);
	if (cmd->origin)
	{
		if (cmd->red_in(cmd->origin) == FALSE)
			return (FALSE);
	}
	return (TRUE);
}
