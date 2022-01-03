/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:19:25 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/01 22:27:15 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "read_input.h"

typedef struct s_minishell
{
	t_gc		gc;
	t_readin	readin;
	t_vector	tokens;
	t_vector	*env;
	int		exit_state;
}			t_msh;

void		exit_error(t_msh *msh, char *error, int size);
void		exit_program(t_msh *msh, int state);
void		*assert_gc(t_msh *msh, void *data, void (*f)(void *));
void		*assert_malloc(t_msh *msh, void *data);
BOOL		assert_bool(t_msh *msh, BOOL check);
int			assert_errno(t_msh *msh, int i);
char		*get_input(t_msh *msh);
BOOL		init_env(t_msh *msh, char **env);
char		*get_env(t_msh *msh, char *name);

#endif
