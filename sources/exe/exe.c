/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 12:37:08 by aldamien          #+#    #+#             */
/*   Updated: 2021/12/19 19:20:22 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"
#include <sys/types.h>
#include <sys/wait.h>

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
}
