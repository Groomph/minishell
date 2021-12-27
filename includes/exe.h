/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 12:36:54 by aldamien          #+#    #+#             */
/*   Updated: 2021/12/27 11:34:30 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXE_H
# define EXE_H

# include "minishell.h"
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>

void	execute(t_msh *msh, char **env, t_vector *v_cmd);

#endif
