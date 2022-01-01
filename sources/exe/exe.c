/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 15:53:17 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/01 13:02:35 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "exe.h"
#include "parsing.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

static int	execute_cmd(t_msh *msh, t_vector *cmds, int i, int fd_in)
{
	int			pid;
	int			pipe_tab[2];
	t_command	*cmd;

	cmd = cmds->arr[i];
	pipe(pipe_tab);
	pid = fork();
	if (pid == 0)
	{
		pipe_redirections(fd_in, pipe_tab, i, cmds->size);
		if (!file_redirections(cmd))
			exit(1);
		if (cmd->name)
		{
			execve(cmd->name, (char **)cmd->args->arr,
				(char **)msh->env->arr);
			write(1, "command not existing\n", 21);
		}
		exit(1);
	}
	wait(&msh->exit_state);
	close(pipe_tab[1]);
	close(fd_in);
	return (pipe_tab[0]);
}

static int	execute(t_msh *msh, t_vector *cmds, int i, int fd_in)
{
	int			fd_out;
	t_command	*command;
	int			type;

	command = cmds->arr[i];
	type = is_builtin(command->args->arr[0]);
	if (type == -1)
		fd_out = execute_cmd(msh, cmds, i, fd_in);
	else if (cmds->size == 1)
		fd_out = execute_builtin(msh, cmds, i, fd_in);
	else
		fd_out = execute_builtin_pipe(msh, cmds, i, fd_in);
	return (fd_out);
}

void	execute_loop(t_msh *msh, t_vector *cmds)
{
	int	i;
	int	fd_out;

	i = 0;
	fd_out = dup(0);
	while (cmds->arr[i])
	{
		fd_out = execute(msh, cmds, i, fd_out);
		i++;
	}
	close(fd_out);
}
