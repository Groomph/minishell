/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 13:22:07 by aldamien          #+#    #+#             */
/*   Updated: 2022/01/03 17:02:12 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"
#include "minishell.h"
#include "libft.h"

void	ft_env(t_msh *msh, char **arr, BOOL forked)
{
	int		i;
	char	**env;

	(void)arr;
	env = (char **)msh->env->arr;
	i = 0;
	while (env[i])
	{
		write(1, env[i], string_len(env[i]));
		write(1, "\n", 1);
		i++;
	}
	if (forked)
		exit_program(msh, 0);
	msh->exit_state = 0;
}
