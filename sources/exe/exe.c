/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 12:37:08 by aldamien          #+#    #+#             */
/*   Updated: 2022/01/03 16:52:35 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "exe.h"
#include "parsing.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

static void	child_work(t_msh *msh, t_vector *cmds, int i)
{
	t_command	*cmd;

	connect_pipe((t_command **)cmds->arr, i, cmds->size);
	cmd = cmds->arr[i];
	if (!file_redirections(cmd))
		exit_program(msh, 1);
	if (cmd->name && find_path(msh, cmd))
	{
		execve(cmd->name, (char **)cmd->args->arr,
			(char **)msh->env->arr);
		write(1, "command not existing\n", 21);
	}
	exit_program(msh, 1);
}

static void	execute_cmd(t_msh *msh, t_vector *cmds, int i)
{
	int			pid;
	t_command	*cmd;

	cmd = cmds->arr[i];
	pipe(cmd->pipe);
	pid = fork();
	if (pid == 0)
		child_work(msh, cmds, i);
	wait(&msh->exit_state);
	close(cmd->pipe[1]);
	if (i == cmds->size - 1)
		close(cmd->pipe[0]);
	if (i > 0)
	{
		cmd = cmds->arr[i - 1];
		close(cmd->pipe[0]);
	}
}

void	execute_loop(t_msh *msh, t_vector *cmds)
{
	int			i;
	int			type;
	t_command	*cmd;

	i = 0;
	while (cmds->arr[i])
	{
		cmd = cmds->arr[i];
		type = is_builtin(cmd->args->arr[0]);
		if (type == -1)
			execute_cmd(msh, cmds, i);
		else if (cmds->size == 1)
			execute_builtin(msh, cmd);
		else
			execute_builtin_pipe(msh, cmds, i);
		i++;
	}
}
