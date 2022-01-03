/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 21:11:42 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/02 21:46:48 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>

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

BOOL	find_path(t_msh *msh, t_command *cmd)
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

BOOL	restore_std(int *term_fd)
{
	BOOL	state;

	state = TRUE;
	if (dup2(term_fd[0], STDIN_FILENO) == -1)
	{
		state = FALSE;
		perror("Unable to restaure STDIN");
	}
	close(term_fd[0]);
	if (dup2(term_fd[1], STDOUT_FILENO) == -1)
	{
		state = FALSE;
		perror("Unable to restaure STDOUT");
	}
	close(term_fd[1]);
	return (state);
}

BOOL	save_std(int *term_fd)
{
	BOOL	state;

	state = TRUE;
	term_fd[0] = dup(STDIN_FILENO);
	if (term_fd[0] == -1)
	{
		state = FALSE;
		perror("Unable to save STDIN");
	}
	term_fd[1] = dup(STDOUT_FILENO);
	if (term_fd[1] == -1)
	{
		state = FALSE;
		perror("Unable to save STDOUT");
	}
	return (state);
}
