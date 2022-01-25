/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 12:36:54 by aldamien          #+#    #+#             */
/*   Updated: 2022/01/25 18:28:07 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXE_H
# define EXE_H

# include "minishell.h"
# include "libft.h"
# include "parsing.h"
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>

void	execute_loop(t_msh *msh, t_vector *cmd);

int		is_builtin(char *name);
void	execute_builtin(t_msh *msh, t_command *cmd);
void	execute_builtin_pipe(t_msh *msh, t_vector *cmds, int i);

void	connect_pipe(t_command **cmds, int i, int len);
BOOL	file_redirections(t_command *cmd);
BOOL	find_path(t_msh *msh, t_command *cmd);

BOOL	save_std(int *term_tab);
BOOL	restore_std(int *term_tab);

BOOL	set_signal(int sig, void (*f)(int));
BOOL	restaure_signal(int sig);
void	handler(int sig);

void	what_sig_kill(t_msh *msh);

void	ft_echo(t_msh *msh, char **arr, BOOL forked);
void	ft_cd(t_msh *msh, char **arr, BOOL forked);
void	ft_pwd(t_msh *msh, char **arr, BOOL forked);
void	ft_export(t_msh *msh, char **arr, BOOL forked);
void	ft_unset(t_msh *msh, char **arr, BOOL forked);
void	ft_env(t_msh *msh, char **arr, BOOL forked);
void	ft_getenv(t_msh *msh, char **arr, BOOL forked);
void	ft_exit(t_msh *msh, char **arr, BOOL forked);

#endif
