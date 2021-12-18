/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:55:36 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/18 00:57:22 by rsanchez         ###   ########.fr       */
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

void	*assert_gc(t_msh *msh, void *data, void (*f)(void *))
{
	if (!data)
	{
		exit_error(msh, "error1\n", 7);
	}
	if (!gc_add(&(msh->gc), data, f))
	{
		f(data);
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

BOOL	assert_bool(t_msh *msh, BOOL check)
{
	if (!check)
	{
		exit_error(msh, "error4\n", 7);
	}
	return (check);
}

int	assert_errno(t_msh *msh, int i)
{
	if (i == -1)
	{
		exit_error(msh, "minishell: ", -1);
	}
	return (i);
}
