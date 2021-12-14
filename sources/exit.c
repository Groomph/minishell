/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:00:06 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/13 23:35:55 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

void	exit_program(t_msh *msh)
{
	vector_purge(&(msh->tokens), free);
	gc_purge(&(msh->gc));
	exit(1);
}
