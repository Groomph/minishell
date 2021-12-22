/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:27:32 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/22 16:24:48 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

BOOL	reset_signal(void)
{
	struct sigaction	sig;
	struct sigaction	sig2;

	mem_set(&sig, 0, sizeof(sig));
	sig.sa_handler = SIG_DFL;
	if (sigaction(SIGQUIT, &sig, NULL) == -1)
	{
		perror("read_input: unable to restaure SIGQUIT: ");
		return (FALSE);
	}
	mem_set(&sig2, 0, sizeof(sig2));
	sig2.sa_handler = SIG_DFL;
	if (sigaction(SIGINT, &sig2, NULL) == -1)
	{
		perror("read_input: unable to restaure SIGINT: ");
		return (FALSE);
	}
	return (TRUE);
}

static void	sigint_catch(int sig)
{
	if (sig == SIGINT)
	{
		write(0, "^C", 2);
	}
}

//SIGWINCH SIGNAL CHANGEMENT TAILLE FENETRE

BOOL	init_signal(void)
{
	struct sigaction	sig;
	struct sigaction	sig2;

	mem_set(&sig, 0, sizeof(sig));
	sig.sa_handler = SIG_IGN;
	if (sigaction(SIGQUIT, &sig, NULL) == -1)
	{
		perror("read_input: unable to ignore SIGQUIT: ");
		return (FALSE);
	}
	mem_set(&sig2, 0, sizeof(sig2));
	sig2.sa_handler = sigint_catch;
	if (sigaction(SIGINT, &sig2, NULL) == -1)
	{
		perror("read_input: unable to detourn SIGQUIT: ");
		return (FALSE);
	}
	return (TRUE);
}
