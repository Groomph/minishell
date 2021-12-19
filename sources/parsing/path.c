/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 12:44:04 by aldamien          #+#    #+#             */
/*   Updated: 2021/12/19 18:29:37 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static char	*paths_finder(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (str_n_comp("PATH", env[i], 4) == 0)
			return (string_duplicate(&env[i][5], -1));
		i++;
	}
	return (NULL);
}

BOOL	get_path(t_msh *msh, char **env)
{
	char	*verif;

	verif = paths_finder(env);
	if (verif)
		msh->paths = string_split(verif, ':');
	else
		return (FALSE);
	free(verif);
	return (TRUE);
}
