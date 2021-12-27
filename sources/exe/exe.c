/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 12:37:08 by aldamien          #+#    #+#             */
/*   Updated: 2021/12/27 15:40:50 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"
#include <sys/types.h>
#include <sys/wait.h>
#include "parsing.h"

static int	fork_loop(t_msh *msh, char **env, t_command *s_cmd, int *fd_in)
{
	int	pid;
	int	pipe_tab[2];

	(void)msh;
	pipe(pipe_tab);
	pid = fork();
	if (pid == 0)
	{
		if (fd_in[1] == 1)
		{
			dup2(pipe_tab[1], STDOUT_FILENO);
		}
		close(pipe_tab[1]);
//		close(pipe_tab[0]); leak potentiel de fd
		dup2(fd_in[0], 0);
		close(fd_in[0]);
		if (s_cmd->dest)
			s_cmd->red_out(s_cmd->dest);
		if (s_cmd->origin)
			s_cmd->red_in(s_cmd->origin);
		execve(s_cmd->name, (char **)s_cmd->args->arr, env);
		write(1, "command not existing\n", 21);
		exit(0);
	}
	wait(&pid);
	close(pipe_tab[1]);
	close(fd_in[0]);
	return (pipe_tab[0]);
}

void	execute(t_msh *msh, char **env, t_vector *v_cmd)
{
	int	i;
	int	fd_out[2];

	i = 0;
	fd_out[0] = dup(0);
	while (v_cmd->arr[i])
	{
		if (v_cmd->arr[i + 1])
			fd_out[1] = 1;
		else
			fd_out[1] = 0;
		fd_out[0] = fork_loop(msh, env, (t_command *)v_cmd->arr[i], fd_out);
		i++;
	}
	return ;
}
