/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 02:25:25 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/01 22:49:48 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include <unistd.h>
#include <stdio.h>

void	pipe_redirections(int fd_in, int pipe_tab[], int pos, int len_pipe)
{
	close(pipe_tab[0]);
	if (pos < len_pipe - 1)
	{
		if (dup2(pipe_tab[1], STDOUT_FILENO) == -1)
			perror("Unable to dup2 stdout");
	}
	close(pipe_tab[1]);
	dup2(fd_in, 0);
	close(fd_in);
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
