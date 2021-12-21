/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:07:46 by aldamien          #+#    #+#             */
/*   Updated: 2021/12/21 13:30:00 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"
# include "lexer.h"


typedef struct s_command
{
	char	*name;
	char	**args;
	void	*red_in();
	char	*origin;
	void	*red_out();
	char	*dest;
}		t_command;

// parse_command

char	**get_command(t_msh *msh, int *i);
t_vector	*parse_line(t_msh *msh);

// parse_env

BOOL	set_path(t_msh *msh, char **env);

#endif
