/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:00:06 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/22 13:14:27 by romain           ###   ########.fr       */
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
	vector_purge(&(msh->tokens), NULL);
	array_clear((void **)msh->paths);
	clear_readinput(&(msh->readin));
	exit(1);
}
