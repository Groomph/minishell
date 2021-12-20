/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:22:00 by aldamien          #+#    #+#             */
/*   Updated: 2021/12/20 14:44:40 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"
#include "stdio.h"
#include "unistd.h"

t_vector	*parse_line(t_msh *msh)
{
	t_vector	*line;
	char		*token;
	int		i;

	line = vector_new(3);
	assert_gc(msh, line, (void *)(void *)vector_empty_clear);
	i = 0;
	while (msh->tokens.arr[i])
	{
		token = vector_get(&msh->tokens, i);
		if (get_char_type(token[0]) != OPERATOR)
			assert_bool(msh, vector_add(line, get_command(msh, &i)));
		else
		{
			assert_bool(msh, vector_add(line, msh->tokens.arr[i]));
			i++;
		}
	}
	return (line);
}

char	*find_right_path(t_msh *msh, char *command)
{
	int	i;
	char	*str;
	char	*test;

	i = 0;
	str = strjoin("/", command);
	assert_gc(msh, str, free);
	while (msh->paths[i])
	{
		test = strjoin(msh->paths[i], str);
		assert_gc(msh, test, free);
		if (access(test, X_OK) == 0)
			break;
		i++;
	}
	if (!msh->paths[i])
		return (command);
	return (test);
}

char	**get_command(t_msh *msh, int *i)
{
	char	**cmds;
	char	*token;
	int	j;
	int	k;

	j = (*i);
	token = vector_get(&msh->tokens, (*i));
	while (token && get_char_type(token[0]) != OPERATOR)
	{
		(*i)++;
		token = vector_get(&msh->tokens, (*i));
	}
	cmds = ft_calloc((*i) - j + 1, sizeof(char *));
	assert_gc(msh, cmds, free);
	k = 0;
	while (msh->tokens.arr[j] && j < (*i))
	{
		cmds[k] = vector_get(&(msh->tokens), j); 
		k++;
		j++;
	}
	cmds[0] = find_right_path(msh, cmds[0]);
	return (cmds);
}
