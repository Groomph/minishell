/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:55:36 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/16 01:04:16 by rsanchez         ###   ########.fr       */
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

void	*assert_malloc(t_msh *msh, void *data)
{
	if (!data)
	{
		exit_error(msh, "error3\n", 7);
	}
	return (data);
}

char	assert_str(t_msh *msh, t_vecstr *v, char c)
{
	if (vecstr_add(v, c))
	{
		exit_error(msh, "error4\n", 7);
	}
	return (c);
}
