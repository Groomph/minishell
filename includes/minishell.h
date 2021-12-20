/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:19:25 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/20 14:24:50 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <termios.h>

typedef struct termios	t_term;

typedef struct s_minishell
{
	t_gc		gc;
	t_gc		hist_gc;
	t_vector	tokens;
	t_vector	history;
	t_term		term_config;
	char		**paths;
}			t_msh;

BOOL		init_terminal(t_msh *msh);
BOOL		reset_terminal(t_msh *msh);
void		exit_error(t_msh *msh, char *error, int size);
void		exit_program(t_msh *msh);
void		*assert_gc(t_msh *msh, void *data, void (*f)(void *));
void		*assert_malloc(t_msh *msh, void *data);
BOOL		assert_bool(t_msh *msh, BOOL check);
int			assert_errno(t_msh *msh, int i);
int			get_chartype(int gotten);
char		*get_input(t_msh *msh);
void		tokenizer(t_msh *msh, char *input);

#endif
