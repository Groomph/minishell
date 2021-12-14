/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:19:25 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/13 23:33:45 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "libft.h"

enum	e_char_type
{
	OPERATOR = 0,
	QUOTE,
	CHARACTER,
	UNPRINT,
	BLANK,
	ERROR
};

enum	e_token_type
{
	TOK_OPERATOR = 0,
	TOK_QUOTED_STR,
	TOK_WORD,
	TOK_ERROR
};

typedef struct s_minishell
{
	t_gc		gc;
	t_vector	tokens;
}			t_msh;

void			exit_program(t_msh *msh);
void			*assert_vector(t_msh *msh, t_vector *v, void *data);
void			*assert_gc(t_msh *msh, void *data);

char			*get_input(t_msh *msh);
BOOL			is_closed_quote(char *input);

void			tokenizer(t_msh *msh, char *input);


#endif
