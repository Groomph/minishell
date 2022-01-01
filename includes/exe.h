/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 12:36:54 by aldamien          #+#    #+#             */
/*   Updated: 2022/01/01 12:28:34 by rsanchez         ###   ########.fr       */
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

int	is_builtin(char *name);
int	execute_builtin(t_msh *msh, t_vector *cmds, int i, int fd_in);
int	execute_builtin_pipe(t_msh *msh, t_vector *cmds, int i, int fd_in);

void	pipe_redirections(int fd_in, int pipe_tab[], int pos, int len_pipe);
BOOL	file_redirections(t_command *cmd);

//void	ft_echo(t_msh *msh, char **arr, char **env);
//void	ft_cd(t_msh *msh, char **arr, char **env);
//void	ft_pwd(t_msh *msh, char **arr, char **env);
void	ft_export(t_msh *msh, char **arr, BOOL forked);
//void	ft_unset(t_msh *msh, char **arr, char **env);
//void	ft_env(t_msh *msh, char **arr, char **env);
//void	ft_exit(t_msh *msh, char **arr, char **env);

#endif
