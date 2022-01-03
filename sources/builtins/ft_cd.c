/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 23:15:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/03 00:58:18 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>

static int	get_path(t_msh *msh, char *arg, char **path)
{
	if (!arg)
	{
		*path = get_env(msh, "HOME");
		if (!(*path))
		{
			write(1, "cd: HOME is unset\n", 14);
			return (1);
		}
	}
	else
		*path = arg;
	return (0);
}

int	ft_cd(t_msh *msh, char **av, BOOL forked)
{
	int		error;
	char	*path;

	error = 0;
	if (av[2])
	{
		write(1, "cd: too many arguments\n", 23);
		error = 1;
	}
	else
	{
		error = get_path(msh, av[1], &path);
		if (path && chdir(path) == -1)
		{
			perror("cd");
			error = 1;
		}
	}
	if (forked)
		exit_program(msh, error);
	return (error);
}
