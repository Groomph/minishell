/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:07:46 by aldamien          #+#    #+#             */
/*   Updated: 2021/12/27 16:29:18 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"
# include "libft.h"

typedef struct s_command
{
	char		*name;
	t_vector	*args;
	BOOL		(*red_in)(char *);
	char		*origin;
	void		(*red_out)(char *);
	char		*dest;
	int			id;
}			t_command;

// parse_command

int			parser(t_msh *msh, char **tokens, t_vector **list);
int			parse_word(t_msh *msh, t_command *cmd, char *token);
int			parse_redirection(t_msh *msh, t_command *cmd,
				char *token, char *next);

char		*trim_expand_var(t_msh *msh, char *str);
char		*expand_heredoc(t_msh *msh, char *str);

char		*find_right_path(t_msh *msh, char *command);

BOOL		create_heredoc(t_msh *msh, t_command *cmd);

// parse_env

BOOL		set_path(t_msh *msh, char **env);

#endif
