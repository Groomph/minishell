/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:34:35 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/16 03:08:20 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

enum	e_termcaps
{
	ARROW_UP = 0,
	ARROW_DOWN,
	ARROW_RIGHT,
	ARROW_LEFT,
	DELETE
};

typedef struct	s_input
{
	char		*input;    //input saisi par le user
	t_vecstr	*in;        //la string tapé par le user sans termcaps
	t_vecstr	*tmp;      //la string sur laquelle on travaille
	int		i;
	int		hist_i;
}		t_input;

void	interpret_input(t_msh *msh, t_input *input);

void		history_up(t_vector *history, t_input *input);
void		history_down(t_vector *history, t_input *input);
void		move_left(t_vector *history, t_input *input);
void		move_right(t_vector *history, t_input *input);
void		char_delete(t_vector *history, t_input *input);

void	insert_char(t_msh *msh, t_input *input, char c);
