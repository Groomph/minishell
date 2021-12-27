/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 12:36:54 by aldamien          #+#    #+#             */
/*   Updated: 2021/12/27 17:56:09 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXE_H
# define EXE_H

# include "minishell.h"
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>

void	execute(t_msh *msh, char **env, t_vector *v_cmd);
void	ft_echo(t_msh *msh, char **arr, char **env);
void	ft_cd(t_msh *msh, char **arr, char **env);
void	ft_pwd(t_msh *msh, char **arr, char **env);
void	ft_export(t_msh *msh, char **arr, char **env);
void	ft_unset(t_msh *msh, char **arr, char **env);
void	ft_env(t_msh *msh, char **arr, char **env);
void	ft_exit(t_msh *msh, char **arr, char **env);

#endif
