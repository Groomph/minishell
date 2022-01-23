/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:58:28 by aldamien          #+#    #+#             */
/*   Updated: 2022/01/23 18:10:33 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

#include <stdio.h>

BOOL	init_env(t_msh *msh, char **env)
{
	int		i;
	char	*tmp;

	i = 0;
	msh->env = vector_new(20);
	if (!(msh->env))
		return (FALSE);
	if (!env)
		return (FALSE);
	while (env[i])
	{
		tmp = string_duplicate(env[i], -1);
		if (tmp == NULL)
			return (FALSE);
		if (vector_add(msh->env, tmp) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
//add env to check for env unset
//should segfault, but didn't
//still fixed
