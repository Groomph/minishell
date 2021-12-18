/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:34:35 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/18 14:23:55 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "minishell.h"

enum	e_termcaps
{
	ARROW_UP = 0,
	ARROW_DOWN,
	ARROW_RIGHT,
	ARROW_LEFT,
	DELETE
};

	//buffer de l'actuel input
	//la string sur laquelle on travaille
	//position du curseur
	//position dans l'historique
	//taille de ce qui affiché

typedef struct s_input
{
	t_vecstr	*in;
	t_vecstr	*tmp;
	int			i;
	int			hist_i;
	int			display_size;
}			t_input;

void		interpret_input(t_msh *msh, t_input *input, char *buf);
void		add_to_history(t_msh *msh, t_vecstr *input);

void		history_up(t_vector *history, t_input *input);
void		history_down(t_vector *history, t_input *input);
void		move_left(t_vector *history, t_input *input);
void		move_right(t_vector *history, t_input *input);
void		delete_char(t_vector *history, t_input *input);

void		insert_char(t_msh *msh, t_input *input, char c);
void		backspace(t_input *input);

void		cursor_left(int nb);
void		cursor_right(int nb);

void		refresh_display(t_input *input);
void		refresh_deleted(t_input *input);
//void		refresh_display(int cursor, char *str, int str_s, int display_s);

#endif
