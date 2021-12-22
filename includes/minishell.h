/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:19:25 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/21 19:24:14 by romain           ###   ########.fr       */
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
	char		**paths;
}			t_msh;

void		exit_error(t_msh *msh, char *error, int size);
void		exit_program(t_msh *msh);
void		*assert_gc(t_msh *msh, void *data, void (*f)(void *));
void		*assert_malloc(t_msh *msh, void *data);
BOOL		assert_bool(t_msh *msh, BOOL check);
int			assert_errno(t_msh *msh, int i);
char		*get_input(t_msh *msh);

#endif
