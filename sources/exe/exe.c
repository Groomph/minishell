/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 12:37:08 by aldamien          #+#    #+#             */
/*   Updated: 2021/12/23 15:39:01 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"
#include <sys/types.h>
#include <sys/wait.h>
#include "parsing.h"

void	fork_loop(char **env, t_command *s_cmd)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		if (s_cmd->dest)
			s_cmd->red_out(s_cmd->dest);
		if (s_cmd->origin)
			s_cmd->red_in(s_cmd->origin);
		execve(s_cmd->name, s_cmd->args, env);
		printf("command not existing\n");
		exit(0);
	}
        wait(&pid);
}

void    execute(t_msh *msh, char **env, t_vector *v_cmd)
{
        int     i;
        
        (void)msh;
	i = 0;
	while (v_cmd->arr[i])
	{
		if (i % 2 == 0)
			fork_loop(env, (t_command *)v_cmd->arr[i]);
		i++;
	}
        return ;
}

/*
void	execute(t_msh *msh, char **env, char **cmd_full)
{
	int	pid;
	
	(void)msh;
	pid = fork();
	if (pid == 0)
	{
		execve(cmd_full[0], cmd_full, env);
		printf("command not existing\n");
		exit(0);
	}
	wait(&pid);
	return;
}*/
