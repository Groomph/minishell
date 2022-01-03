/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:48:30 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/03 22:04:53 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

BOOL	set_signal(int sig, void (*f)(int sig))
{
	struct sigaction	s_sig;

	mem_set(&s_sig, 0, sizeof(sig));
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

	mem_set(&s_sig, 0, sizeof(sig));
	s_sig.sa_handler = SIG_DFL;
	if (sigaction(sig, &s_sig, NULL) == -1)
	{
		perror("unable to restaure signal: ");
		return (FALSE);
	}
	return (TRUE);
}

int	what_sig_kill(int status)
{
	if (status != 0)
	{
		if (WIFSIGNALED(status) == TRUE)
			return (WTERMSIG(status) + 128);
		return (WEXITSTATUS(status));
	}
	return (0);
}

void	handler(int sig)
{
	if (sig == SIGINT)
		write(1, "\n", 1);
	else if (sig == SIGQUIT)
		write(1, "QUIT (core dumped)\n", 19);
}
