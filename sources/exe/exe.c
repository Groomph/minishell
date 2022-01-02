/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 15:53:17 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/01 22:45:26 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "exe.h"
#include "parsing.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

static char	*get_final_path(t_msh *msh, char **paths, char *name, char *old)
{
	int		i;
	char	*test;

	i = 0;
	while (paths[i])
	{
		test = strjoin(paths[i], name);
		assert_gc(msh, test, free);
		if (access(test, X_OK) == 0)
			break ;
		i++;
	}
	if (!paths[i])
		return (old);
	return (test);
}

static BOOL	find_path(t_msh *msh, t_command *cmd)
{
	char	*paths;
	char	**paths_tab;
	char	*name;

	paths = get_env(msh, "PATH");
	if (!paths)
	{
		write(2, "PATH is unset\n", 14);
		return (FALSE);
	}
	paths_tab = string_split(paths, ':');
	if (!paths_tab)
		return (FALSE);
	assert_gc(msh, paths_tab, (void *)(void *)array_clear);
	name = strjoin("/", cmd->name);
	if (!name)
		return (FALSE);
	assert_gc(msh, name, free);
	cmd->name = get_final_path(msh, paths_tab, name, cmd->name);
	return (TRUE);
}

static int	execute_cmd(t_msh *msh, t_vector *cmds, int i, int fd_in)
{
	int			pid;
	int			pipe_tab[2];
	t_command	*cmd;
	int			term_fd[2];

	cmd = cmds->arr[i];
	pipe(pipe_tab);
	save_std(term_fd);
	pid = fork();
	if (pid == 0)
	{
		close(term_fd[0]);
		close(term_fd[1]);
		pipe_redirections(fd_in, pipe_tab, i, cmds->size);
		if (!file_redirections(cmd))
			exit_program(msh, 1);
		if (cmd->name && find_path(msh, cmds->arr[i]))
		{
			execve(cmd->name, (char **)cmd->args->arr,
					(char **)msh->env->arr);
			write(1, "command not existing\n", 21);
		}
		exit_program(msh, 1);
	}
	wait(&msh->exit_state);
	restaure_std(term_fd);
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
