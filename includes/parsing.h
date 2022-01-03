/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:07:46 by aldamien          #+#    #+#             */
/*   Updated: 2022/01/03 21:11:01 by romain           ###   ########.fr       */
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
	int		pipe[2];
	int			id;
}			t_command;

// parse_command

int			parser(t_msh *msh, char **tokens, t_vector **list);
int			parse_word(t_msh *msh, t_command *cmd, char *token);
int			parse_redirection(t_msh *msh, t_command *cmd,
				char *token, char *next);

char		*trim_expand_var(t_msh *msh, char *str);
int		expand_var(t_msh *msh, t_vecstr *string, int i);
int		expand_exitstate(t_msh *msh, t_vecstr *string, int i);

BOOL		create_heredoc(t_msh *msh, t_command *cmd);

#endif
