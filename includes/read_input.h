/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:51:04 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/24 16:46:06 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_INPUT_H
# define READ_INPUT_H

# include "libft.h"
# include <termios.h>

typedef enum e_state
{
	READ = 0,
	NEWLINE,
	EOT,
	INTERRUPTED,
	ERROR
}		t_state;

typedef struct termios	t_term;

typedef struct s_read_input
{
	t_gc		gc;
	t_vector	history;
	t_term		term_config;
	t_state		state;
}			t_readin;

enum	e_termcaps
{
	ARROW_UP = 0,
	ARROW_DOWN,
	ARROW_RIGHT,
	ARROW_LEFT,
	DELETE
};

//	int	i	position curseur string
//	int	display_i	position curseur display

typedef struct s_input
{
	t_vecstr	*in;
	t_vecstr	*focus;
	int			i;
	int			hist_i;
	int			display_i;
	int			display_size;
	int			col;
	int			row;
}			t_input;

char		*read_input(t_readin *readin, char *prompt, int size);
void		add_history(t_readin *readin, char *input);

BOOL		init_readinput(t_readin *readin);
void		clear_readinput(t_readin *readin);

BOOL		init_input(t_readin *readin, t_input *input);
void		clear_input(t_input *input);

BOOL		init_terminal(t_readin *readin, t_input *input);
BOOL		reset_terminal(t_readin *readin);
BOOL		init_signal(void);
BOOL		reset_signal(void);

BOOL		interpret_input(t_readin *readin, t_input *input,
				char *buf, int size);

BOOL		history_up(t_vector *history, t_input *input);
BOOL		history_down(t_vector *history, t_input *input);
BOOL		move_left(t_vector *history, t_input *input);
BOOL		move_right(t_vector *history, t_input *input);
BOOL		delete_char(t_vector *history, t_input *input);

BOOL		insert_char(t_input *input, char *buf, int size);
void		backspace(t_input *input);

int			get_utf_size(char c);
int			get_utf_dist(char *str, int i);
int			get_display_size(char *str);

void		cursor_left(int nb);
void		cursor_right(int nb);

void		refresh_from_position(t_input *input, int old_pos);
void		refresh_deleted(t_input *input);
void		refresh_display(t_input *input, int old_i, int old_size);

#endif
