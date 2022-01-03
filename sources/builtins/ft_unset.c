/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 14:28:25 by aldamien          #+#    #+#             */
/*   Updated: 2022/01/03 16:30:56 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"
#include "minishell.h"
#include "libft.h"

static BOOL	ft_is_valid(char *token)
{
	int	i;

	if (!is_alpha(token[0]))
		return (FALSE);
	i = 1;
	while (token[i])
	{
		if (is_alphanum(token[i]))
			i++;
		else
			return (FALSE);
	}
	return (TRUE);
}

static int	second_loop(t_msh *msh, char *arr, char **env)
{
	int	i;
	int	len;

	i = 0;
	len = string_len(arr);
	if (ft_is_valid(arr) == TRUE)
	{
		while (env[i])
		{
			if (str_n_comp(env[i], arr, len) == 0)
				vector_delone(msh->env, i, free);
			i++;
		}
	}
	else
	{
		printf("unset: %s: invalid parameter name\n", arr);
		return (1);
	}
	return (0);
}

void	ft_unset(t_msh *msh, char **arr, BOOL forked)
{
	int		j;
	char	**env;
	int		error;

	env = (char **)msh->env->arr;
	j = 0;
	error = 0;
	while (arr[++j])
	{
		error += second_loop(msh, arr[j], env);
	}
	if (forked)
		exit_program(msh, error);
	msh->exit_state = error;
}
