/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 12:44:04 by aldamien          #+#    #+#             */
/*   Updated: 2021/12/20 11:39:00 by romain           ###   ########.fr       */
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

BOOL	set_path(t_msh *msh, char **env)
{
	char	*verif;

	verif = paths_finder(env);
	if (!verif)
		return (FALSE);
	msh->paths = string_split(verif, ':');
	free(verif);
	if (!(msh->paths))
		return (FALSE);
	return (TRUE);
}
