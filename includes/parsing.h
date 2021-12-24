/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:07:46 by aldamien          #+#    #+#             */
/*   Updated: 2021/12/24 11:37:11 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"
# include "lexer.h"
# include <unistd.h>
# include <stdio.h>

typedef struct s_command
{
	char	*name;
	char	**args;
	void	(*red_in)(t_msh *msh, char *);
	char	*origin;
	void	(*red_out)(char *);
	char	*dest;
}		t_command;

// parse_command

t_command	*get_command(t_msh *msh, int *i);
t_vector	*parse_line(t_msh *msh);
char		*find_right_path(t_msh *msh, char *command);

// parse_env

BOOL	set_path(t_msh *msh, char **env);

// check syntax

int	check_syntax(t_msh *msh);

#endif
