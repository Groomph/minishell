/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:58:28 by aldamien          #+#    #+#             */
/*   Updated: 2022/01/25 22:55:50 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

BOOL	set_pwd(t_msh *msh)
{
	char	buf[PATH_MAX];

	if (getcwd(buf, PATH_MAX) == NULL)
	{
		perror("pwd");
		return (FALSE);
	}
	return (set_env(msh, "PWD", buf));
}

int	get_env_index(t_msh *msh, char *name)
{
	int		i;
	int		len;
	char	**env;

	i = 0;
	len = string_len(name);
	env = (char **)msh->env->arr;
	while (env[i])
	{
		if ((str_n_comp(name, env[i], len) == 0)
			&& env[i][len] == '=')
			return (i);
		i++;
	}
	return (-1);
}

BOOL	set_env(t_msh *msh, char *name, char *var)
{
	int	i;

	i = get_env_index(msh, name);
	name = strjoin(name, "=");
	var = strjoin_free(name, var, TRUE, FALSE);
	if (!name || !var)
	{
		perror("malloc");
		return (FALSE);
	}
	if (i >= 0)
	{
		free(msh->env->arr[i]);
		msh->env->arr[i] = var;
		return (TRUE);
	}
	if (vector_add(msh->env, var))
		return (TRUE);
	free(var);
	perror("malloc");
	return (FALSE);
}

char	*get_env(t_msh *msh, char *name)
{
	int		i;
	int		len;
	char	**env;

	i = 0;
	len = string_len(name);
	env = (char **)msh->env->arr;
	while (env[i])
	{
		if ((str_n_comp(name, env[i], len) == 0)
			&& env[i][len] == '=')
			return (&(env[i][len + 1]));
		i++;
	}
	return (NULL);
}

BOOL	init_env(t_msh *msh, char **env)
{
	int		i;
	char	*tmp;

	i = 0;
	msh->env = vector_new(20);
	if (!(msh->env))
		return (FALSE);
	while (env && env[i])
	{
		tmp = string_duplicate(env[i], -1);
		if (tmp == NULL)
			return (FALSE);
		if (vector_add(msh->env, tmp) == FALSE)
			return (FALSE);
		i++;
	}
	if (!get_env(msh, "PWD"))
		set_pwd(msh);
	return (TRUE);
}
//add env to check for env unset
//should segfault, but didn't
//still fixed
