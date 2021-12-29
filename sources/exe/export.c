/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:02:48 by aldamien          #+#    #+#             */
/*   Updated: 2021/12/29 19:38:36 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"
#include "minishell.h"
#include "libft.h"

static BOOL	is_alpha(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (TRUE);
	else if (c >= 'a' && c <= 'z')
		return (TRUE);
	return (FALSE);
}

static int	get_size_name(char *var)
{
	int	i;

	i = 0;
	while (var[i])
	{
		if (var[i] == '=')
			return (i);
		i++;
	}
	return (i);
}

static int	get_index(char **env, char *name)
{
	int	i;
	int	size_name;

	i = 0;
	size_name = get_size_name(name);
	while (env[i])
	{
		if (str_n_comp(env[i], name, size_name) == 0)
			return (i);
		i++;
	}
	return (-1);
}

static BOOL	pars_export(t_msh *msh, char *str)
{
	int	i;

	if (!is_alpha(str[0]))
		return (FALSE);	
	i = get_index((char **)msh->env->arr, str);
//	printf("%d\n", i);
//	printf("%s\n", msh->env->arr[i]);
	if (i >= 0)
	{
		str = string_duplicate(str, -1);
		if (!str)
			return (FALSE);
		free(msh->env->arr[i]);
		msh->env->arr[i] = str;
	}
	else
	{
		printf("on entre jamais ici?!\n");
		if (!vector_add(msh->env, str))
			return (FALSE);
	}
	return (TRUE);
}

void	ft_export(t_msh *msh, char **arr, char **env)
{
	int	i;
	int	error;

	(void)env;
	i = 1;
	error = 0;
	printf("dans export: %p\n", msh->env);
	printf("size: %d\n", msh->env->size);
	while (arr[i])
	{
		if (!pars_export(msh, arr[i]))
			error++;
		i++;
	}
/*	i = 0;
	while (msh->env->arr[i])
	{
		printf("%s\n", msh->env->arr[i]);
		i++;
	}*/
	printf("size: %d\n", msh->env->size);
	exit(error);
}
