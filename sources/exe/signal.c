/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:48:30 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/25 19:27:47 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

BOOL	set_signal(int sig, void (*f)(int sig))
{
	struct sigaction	s_sig;

	mem_set(&s_sig, 0, sizeof(s_sig));
	s_sig.sa_handler = f;
	s_sig.sa_flags = SA_RESTART;
	if (sigaction(sig, &s_sig, NULL) == -1)
	{
		perror("unable to set signal: ");
		return (FALSE);
	}
	return (TRUE);
}

BOOL	restaure_signal(int sig)
{
	struct sigaction	s_sig;

	mem_set(&s_sig, 0, sizeof(s_sig));
	s_sig.sa_handler = SIG_DFL;
	if (sigaction(sig, &s_sig, NULL) == -1)
	{
		perror("unable to restaure signal: ");
		return (FALSE);
	}
	return (TRUE);
}

void	handler(int sig)
{
	if (sig == -SIGINT)
		write(2, "\n", 1);
	else if (sig == -SIGQUIT)
		write(2, "QUIT (core dumped)\n", 19);
	else if (sig == -SIGSEGV)
		write(2, "Segmentation fault\n", 19);
}

void	what_sig_kill(t_msh *msh)
{
	pid_t	pid;
	int		status;
	BOOL	sig_display[30];

	pid = 0;
	sig_display[SIGINT] = TRUE;
	sig_display[SIGSEGV] = TRUE;
	sig_display[SIGQUIT] = TRUE;
	while (pid != -1)
	{
		pid = wait(&status);
		if (pid != -1)
		{
			if (WIFSIGNALED(status) == TRUE)
			{
				msh->exit_state = WTERMSIG(status);
				if (sig_display[msh->exit_state])
					handler(-msh->exit_state);
				sig_display[msh->exit_state] = FALSE;
				msh->exit_state += 128;
			}
			else
				msh->exit_state = WEXITSTATUS(status);
		}
	}
}
