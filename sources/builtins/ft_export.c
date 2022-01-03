/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:02:48 by aldamien          #+#    #+#             */
/*   Updated: 2022/01/01 22:25:55 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"
#include "minishell.h"
#include "libft.h"

static int	get_index(char **env, char *var)
{
	int	i;
	int	size_name;

	i = 0;
	while (var[i])
	{
		if (var[i] == '=')
			break ;
		i++;
	}
	size_name = i;
	i = 0;
	while (env[i])
	{
		if (str_n_comp(env[i], var, size_name) == 0)
			return (i);
		i++;
	}
	return (-1);
}

static BOOL	is_valid(char *token)
{
	int	i;

	if (!is_alpha(token[0]))
		return (FALSE);
	i = 1;
	while (token[i] && token[i] != '=')
	{
		if (is_alphanum(token[i]))
			i++;
		else
			return (FALSE);
	}
	return (TRUE);
}

static BOOL	pars_export(t_msh *msh, char *token)
{
	int	i;

	if (!is_valid(token))
	{
		write(1, "export: '", 9);
		write(1, token, string_len(token));
		write(1, "': not a valid identifier\n", 26);
		return (FALSE);
	}
	token = string_duplicate(token, -1);
	if (!token)
		return (FALSE);
	i = get_index((char **)msh->env->arr, token);
	if (i >= 0)
	{
		free(msh->env->arr[i]);
		msh->env->arr[i] = token;
	}
	else
	{
		if (!vector_add(msh->env, token))
			return (FALSE);
	}
	return (TRUE);
}

void	ft_export(t_msh *msh, char **arr, BOOL forked)
{
	int	i;
	int	error;

	i = 1;
	error = 0;
	while (arr[i])
	{
		if (!pars_export(msh, arr[i]))
			error++;
		i++;
	}
	if (forked)
		exit_program(msh, error);
	msh->exit_state = error;
}
