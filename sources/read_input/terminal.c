/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:48:27 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/22 16:25:28 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "read_input.h"
#include <termios.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
//#include <curses.h>
#include <term.h>

BOOL	reset_terminal(t_readin *readin)
{
	if (tcsetattr(0, TCSANOW, &(readin->term_config)) == -1)
	{
		perror("read_input: unable to restaure terminal: ");
		return (FALSE);
	}
	return (TRUE);
}

static BOOL	get_terminal_size(t_input *input)
{
	struct winsize	ws;

	if (tgetflag("co") && tgetflag("li"))
	{
		input->row = tgetnum("li");
		input->col = tgetnum("co");
		return (TRUE);
	}
	ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
	input->row = ws.ws_row;
	input->col = ws.ws_col;
	if (input->row > 0 && input->col > 0)
		return (TRUE);
	perror("Unable to get terminal size: ");
	return (FALSE);
}

BOOL	init_terminal(t_readin *readin, t_input *input)
{
	struct termios	config;

	mem_copy(&config, &(readin->term_config), sizeof(readin->term_config));
	config.c_lflag &= ~(ECHO | ICANON);
	config.c_cc[VMIN] = 1;
	config.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &config) == -1)
	{
		perror("read_input: unable to init terminal: ");
		return (FALSE);
	}
	if (!get_terminal_size(input))
		return (FALSE);
	return (TRUE);
}
