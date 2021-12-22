/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:22:00 by aldamien          #+#    #+#             */
/*   Updated: 2021/12/22 19:39:05 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"
#include "redirect.h"
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
	if (check_syntax(msh) == 0)
		return (NULL);
	while (msh->tokens.arr[i])
	{
		token = vector_get(&msh->tokens, i);
		if (token[0] != '|')
			assert_bool(msh, vector_add(line, get_command(msh, &i)));
		else
		{
			assert_bool(msh, vector_add(line, msh->tokens.arr[i]));
			i++;
		}
	}
	return (line);
}

static t_command	*init_command(t_msh *msh, char **l_cmd)
{
	int	i;
	t_command	*s_cmd;

	s_cmd = malloc(sizeof(t_command));
	assert_gc(msh, s_cmd, free);
	i = 0;
	mem_set(s_cmd, 0, sizeof(t_command));
	s_cmd->args = l_cmd;
	while (l_cmd[i])
	{
		if (l_cmd[i + 1] && l_cmd[i + 1][0] == '<')
		{
			s_cmd->origin = l_cmd[i];
			s_cmd->red_in = red_origin(l_cmd[i + 1]);
			i += 2;
		}
		else if (l_cmd[i][0] == '>')
		{
			s_cmd->dest = l_cmd[i + 1];
			s_cmd->red_out = red_dest(l_cmd[i]);
			i += 2;
		}
		else
		{
			if (s_cmd->name == NULL)
				s_cmd->name = find_right_path(msh, l_cmd[i]);
			l_cmd[0] = l_cmd[i];
			l_cmd++;
		}
	}
	l_cmd[0] = NULL;
	return (s_cmd);
}

void		debug_s_cmd(t_command *s_cmd)
{
	int	i;

	i = 0;
	printf("name = ''%s''\n", s_cmd->name);
	printf("args\n");
	while (s_cmd->args[i])
	{
		printf("args %d = ''%s''\n", i, s_cmd->args[i]);
		i++;
	}
	printf("red_in = %p\n", s_cmd->red_in);
	printf("origin = ''%s''\n", s_cmd->origin);
	printf("red_out = %p\n", s_cmd->red_out);
	printf("dest = ''%s''\n", s_cmd->dest);
}

t_command	*get_command(t_msh *msh, int *i)
{
	t_command	*s_cmd;
	char	**cmds;
	char	*token;
	int	j;
	int	k;

	j = (*i);
	token = vector_get(&msh->tokens, (*i));
	while (token && token[0] != '|')
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
	s_cmd = init_command(msh, cmds);
//	debug_s_cmd(s_cmd);
	return (s_cmd);
}
