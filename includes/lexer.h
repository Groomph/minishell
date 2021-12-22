/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:19:25 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/22 19:52:54 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"
# include "libft.h"

enum	e_char_type
{
	OPERATOR = 0,
	QUOTE,
	CHARACTER,
	BLANK,
	IGNORE,
	CHAR_NB
};

enum	e_token_type
{
	TOK_OPERATOR = 0,
	TOK_QUOTED_STR,
	TOK_WORD,
	NOT_A_TOKEN,
	TOK_NB
};

void		tokenizer(t_msh *msh, char *input);
int		get_token(char *input);

int			get_char_type(unsigned char c);
int			fast_token_type(unsigned char c);
int			get_token_type(int char_type);
BOOL		is_allowed(int char_type, int token_type);

#endif
