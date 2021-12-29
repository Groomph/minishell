/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:58:28 by aldamien          #+#    #+#             */
/*   Updated: 2021/12/29 19:08:54 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env(t_msh *msh, char *name) // verifier pour les len - 1 / len + 1 autours du =
{
	int	i;
	int	len;
	char	**arr;

	i = 0;
	len = string_len(name);
	arr = (char **)msh->env->arr;
	while (arr[i])
	{
		if ((str_n_comp(name, arr[i], len - 1) == 0) &&
			arr[i][len] == '=')
			return (&(arr[i][len + 1]));
		i++;
	}
	return (NULL);
}

BOOL	init_env(t_msh *msh, char **env)
{
	int	i;
	char	*tmp;
	
	i = 0;
	msh->env = vector_new(20);
	if (!(msh->env))
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
