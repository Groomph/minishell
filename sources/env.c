/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:58:28 by aldamien          #+#    #+#             */
/*   Updated: 2021/12/29 17:43:36 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env(t_msh *msh, char *name) // verifier pour les len - 1 / len + 1 autours du =
{
	int	i;
	int	len;

	len = string_len(name);
	i = 0;
	while (msh->env.arr[i])
	{
		if ((str_n_comp(name, msh->env.arr, len - 1) == 0) &&
		(msh->env.arr[len] == '='))
			return (&(msh->env.arr[len + 1]));
		i++;
	}
	return (NULL);
}

BOOL	init_env(t_msh *msh, char **env)
{
	int	i;
	char	*tmp;
	
	i = 0;
	while (env[i])
	{
		tmp = string_duplicate(env[i], -1);
		if (tmp == NULL)
			return (FALSE);
		if (vector_add(&(msh->env), tmp) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}


