/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:48:30 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/03 19:37:15 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <signal.h>

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
	//s_sig.sa_flags = SA_RESTART;
	if (sigaction(sig, &s_sig, NULL) == -1)
	{
		perror("unable to restaure signal: ");
		return (FALSE);
	}
	return (TRUE);
}
