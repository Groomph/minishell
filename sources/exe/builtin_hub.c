/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_hub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 02:23:36 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/01 13:00:52 by rsanchez         ###   ########.fr       */
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
	static char	*builtin[2] = {"export", NULL};
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
	static void	(*adress[2])(t_msh *, char **, BOOL) = {
		ft_export, NULL};

	type = is_builtin(cmd->args->arr[0]);
	adress[type](msh, (char **)cmd->args->arr, forked);
}

int	execute_builtin_pipe(t_msh *msh, t_vector *cmds, int i, int fd_in)
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
		builtin_hub(msh, cmd, TRUE);
		write(1, "not supposed to happen\n", 23);
		exit(1);
	}
	wait(&msh->exit_state);
	close(pipe_tab[1]);
	close(fd_in);
	return (pipe_tab[0]);
}

int	execute_builtin(t_msh *msh, t_vector *cmds, int i, int fd_in)
{
	t_command	*cmd;

	cmd = cmds->arr[i];
	if (!file_redirections(cmd))
		return (fd_in);
	builtin_hub(msh, cmd, FALSE);
	return (fd_in);
}
