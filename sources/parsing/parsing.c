/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:22:00 by aldamien          #+#    #+#             */
/*   Updated: 2021/12/18 18:02:15 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"

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

char	**get_command(t_msh *msh, int *i)
{
	char	**cmds;
	char	*token;
	int	j;

	j = *i;
	token = vector_get(&msh->tokens, *i);
	while (token && get_char_type(token[0]) != OPERATOR)
	{
		(*i)++;
		token = vector_get(&msh->tokens, *i);
	}
	cmds = malloc(sizeof(char *) * (*i + 1));
	assert_gc(msh, cmds, free);
	cmds[*i + 1] = NULL;
	while (msh->tokens.arr[j] && *i != j)
	{
		cmds[j] = msh->tokens.arr[j]; 
		j++;
	}
	return (cmds);
}
