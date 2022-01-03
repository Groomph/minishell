/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_hub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 02:23:36 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/03 16:25:51 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"
#include "exe.h"
#include "libft.h"
#include <sys/types.h>
#include <sys/wait.h>

int	is_builtin(char *name)
{
	static char	*builtin[9] = {
		"export", "env", "unset", "getenv", "echo",
		"pwd", "cd", "exit", NULL};
	int			i;

	i = 0;
	while (name && builtin[i])
	{
		if (str_comp(name, builtin[i]) == 0)
			return (i);
		i++;
	}
	return (-1);
}

static void	builtin_hub(t_msh *msh, t_command *cmd, BOOL forked)
{
	int			type;
	static void	(*adress[9])(t_msh *, char **, BOOL) = {
		ft_export, ft_env, ft_unset, ft_getenv, ft_echo,
		ft_pwd, ft_cd, ft_exit, NULL};

	type = is_builtin(cmd->args->arr[0]);
	adress[type](msh, (char **)cmd->args->arr, forked);
}

static void	child_built(t_msh *msh, t_vector *cmds, int i)
{
	t_command	*cmd;

	connect_pipe((t_command **)cmds->arr, i, cmds->size);
	cmd = cmds->arr[i];
	if (!file_redirections(cmd))
		exit_program(msh, 1);
	builtin_hub(msh, cmd, TRUE);
	write(1, "not supposed to happen\n", 23);
	exit_program(msh, 1);
}

void	execute_builtin_pipe(t_msh *msh, t_vector *cmds, int i)
{
	int			pid;
	t_command	*cmd;

	cmd = cmds->arr[i];
	pipe(cmd->pipe);
	pid = fork();
	if (pid == 0)
		child_built(msh, cmds, i);
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

void	execute_builtin(t_msh *msh, t_command *cmd)
{
	int	term_fd[2];

	save_std(term_fd);
	if (file_redirections(cmd))
		builtin_hub(msh, cmd, FALSE);
	restore_std(term_fd);
}
