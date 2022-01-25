/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 23:15:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/25 22:39:47 by rsanchez         ###   ########.fr       */
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
			write(2, "cd: HOME is unset\n", 18);
			return (1);
		}
	}
	else if (arg[0] == '-' && arg[1] == '\0')
	{
		*path = get_env(msh, "OLDPWD");
		if (!(*path))
		{
			write(2, "cd: OLDPWD is unset\n", 20);
			return (1);
		}
	}
	else
		*path = arg;
	return (0);
}

static int	travel(t_msh *msh, char *arg)
{
	int		error;
	char	*path;
	char	*oldpwd;

	error = get_path(msh, arg, &path);
	if (path)
	{
		oldpwd = get_env(msh, "PWD");
		if (!oldpwd && !set_pwd(msh))
			return (FALSE);
		else if (!oldpwd)
			oldpwd = get_env(msh, "PWD");
		if (chdir(path) == -1)
		{
			perror("cd");
			return (1);
		}
		if (!set_env(msh, "OLDPWD", oldpwd))
			return (1);
		if (!set_pwd(msh))
			return (1);
	}
	return (error);
}

void	ft_cd(t_msh *msh, char **av, BOOL forked)
{
	int		error;

	error = 0;
	if (av[2])
	{
		write(2, "cd: too many arguments\n", 23);
		error = 1;
	}
	else
	{
		error = travel(msh, av[1]);
	}
	if (forked)
		exit_program(msh, error);
	msh->exit_state = error;
}
