/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:48:27 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/16 16:20:56 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <termios.h>
#include <stdio.h>

BOOL	reset_terminal(t_msh *msh)
{
        if (tcsetattr(0, TCSANOW, &(msh->term_config)) == -1)
        {
                perror("reset terminal:");
                return (FALSE);
        }
	return (TRUE);
}

BOOL	init_terminal(t_msh *msh)
{
	struct termios	config;

        if (tcgetattr(0, &(msh->term_config)) == -1)
	{
		return (FALSE);
	}
	mem_copy(&config, &(msh->term_config), sizeof(msh->term_config));
//	config.c_iflag &= ~(ECHO);
	config.c_lflag &= ~(ECHO | ICANON);
	config.c_cc[VMIN] = 1;
	config.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &config) == -1)
	{
		return (FALSE);
	}
	return (TRUE);
}
