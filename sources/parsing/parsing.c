/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:22:00 by aldamien          #+#    #+#             */
/*   Updated: 2021/12/19 15:46:24 by aldamien         ###   ########.fr       */
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
	assert_gc(msh, line, (void *)(void *)vector_clean);
	i = 0;
	while (msh->tokens.arr[i])
	{
		token = vector_get(&msh->tokens, i);
		if (get_char_type(token[0]) != OPERATOR)
			vector_add(line, get_command(msh, &i));
		else
		{
			vector_add(line, msh->tokens.arr[i]);
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
	if (str == NULL)
		perror(NULL);
	while (msh->paths[i])
	{
		test = strjoin(msh->paths[i], str);
		if (access(test, X_OK) != 0)
			free(test);
		else
			break;
		i++;
	}
	free(str);
	if (!msh->paths[i])
		return (command);
	assert_gc(msh, test, free);
	return (test);
}

char	**get_command(t_msh *msh, int *i)
{
	char	**cmds;
	char	*token;
	int	j;
	int	k;

	j = *i;
	token = vector_get(&msh->tokens, *i);
	while (token && get_char_type(token[0]) != OPERATOR)
	{
		(*i)++;
		token = vector_get(&msh->tokens, *i);
	}
	cmds = malloc(sizeof(char *) * (*i - j + 1));
	assert_gc(msh, cmds, free);
	cmds[*i - j + 1] = NULL;
	k = 0;
	while (msh->tokens.arr[j] && *i != j)
	{
		cmds[k] = msh->tokens.arr[j]; 
		printf("%s\n", cmds[k]);
		k++;
		j++;
	}
	return (cmds);
}

