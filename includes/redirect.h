/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:34:20 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/03 16:53:18 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"
# include <stdio.h>
# include "minishell.h"

BOOL	(*red_origin(char *operator))(char *name_file);
void	(*red_dest(char *operator))(char *name_file);

#endif
