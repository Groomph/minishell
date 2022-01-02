/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 21:11:42 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/01 22:53:45 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>

BOOL	restaure_std(int term_fd[])
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

BOOL	save_std(int term_fd[])
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
