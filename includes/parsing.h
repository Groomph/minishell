/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:07:46 by aldamien          #+#    #+#             */
/*   Updated: 2021/12/19 14:58:41 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"
# include "lexer.h"


// parse_command

char	**get_command(t_msh *msh, int *i);
t_vector	*parse_line(t_msh *msh);

// parse_env

BOOL	get_path(t_msh *msh, char **env);

#endif
