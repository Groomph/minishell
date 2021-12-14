/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:55:36 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/13 23:35:20 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>

void	exit_error(t_msh *msh, char *error, int size)
{
	if (size >= 0)
		write(2, error, size);
	else
		perror(error);
	exit_program(msh);
}

void	*assert_vector(t_msh *msh, t_vector *v, void *data)
{
	if (!data || !vector_add(v, data))
	{
		exit_error(msh, "error1\n", 7);
	}
	return (data);
}

void	*assert_gc(t_msh *msh, void *data)
{
	if (!data || !gc_add(&(msh->gc), data, free))
	{
		exit_error(msh, "error2\n", 7);
	}
	return (data);
}
