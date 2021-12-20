/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:00:06 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/20 14:23:15 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdio.h>

//	vector_purge(&(msh->tokens), free);
//	vector_purge(&(msh->history), vecstr_clean);

/*
void	display_gc(t_gc *gc)
{
	int	i;

	printf("%i %i\n", gc->collec.size, gc->collec.max);
	printf("%i %i\n", gc->cleaner.size, gc->cleaner.max);
	i = 0;
	while (i < gc->collec.size)
	{
		printf("%p\n", gc->collec.arr[i]);
		printf("%p\n", gc->cleaner.arr[i]);
		i++;
	}
}
*/
void	exit_program(t_msh *msh)
{
	gc_purge(&(msh->gc));
	gc_purge(&(msh->hist_gc));
	vector_purge(&(msh->tokens), NULL);
	vector_purge(&(msh->history), NULL);
	array_clear((void **)msh->paths);
	if (!(reset_terminal(msh)))
		perror("reset_terminal:");
	exit(1);
}
