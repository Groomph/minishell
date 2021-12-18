/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:00:06 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/18 01:31:07 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdio.h>

//	vector_purge(&(msh->tokens), free);
//	vector_purge(&(msh->history), vecstr_clean);

void	exit_program(t_msh *msh)
{
	gc_purge(&(msh->gc));
	free(msh->tokens.arr);
	free(msh->history.arr);
	if (!(reset_terminal(msh)))
		perror("reset_terminal:");
	exit(1);
}
