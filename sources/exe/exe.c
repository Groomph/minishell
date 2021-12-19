/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 12:37:08 by aldamien          #+#    #+#             */
/*   Updated: 2021/12/19 18:59:05 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"

void	execute(t_msh *msh, char **env, char **cmd_full)
{
	int	pid;
	
	(void)msh;
	pid = fork();
	if (pid > 0)
	{
		execve(cmd_full[0], cmd_full, env);
		printf("command not existing\n");
		exit(0);
	}
	return;
}
