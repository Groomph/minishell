/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:22:00 by aldamien          #+#    #+#             */
/*   Updated: 2021/12/21 15:46:52 by aldamien         ###   ########.fr       */
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

// gestion du >
static void	redirection_out(char *name_file);
{
	(void)name_file;
}

// gestion du >>
static void	redirection_out_2(char *name_file);
{
	(void)name_file;
}

static void	(*red_dest)(char *operator)(char *name_file)
{
	if (operator[1] == 0)
		return (redirection_out);
	return (redirection_out_2);
}

// gestion du <
static void	redirection_in(char *name_file);
{
	(void)name_file;
}

//gestion du <<
static void	redirection_in_2(char *name_file);
{
	(void)name_file;
}

static void	(*red_origin)(char *operator)(char *name_file)
{
	if (operator[1] == 0)
		return (redirection_in);
	return (redirection_in_2);
}

static t_command	*init_command(t_msh *msh, char **l_cmd)
{
	int	i;
	t_command	*s_cmd;

	s_cmd = malloc(sizeof(t_command));
	assert_gc(msh, s_cmd, free);
	i = 0;
	s_cmd->name = NULL;
	s_cmd->args = l_cmd;
	while (l_cmd[i])
	{
		if (l_cmd[i + 1][0] == '<')
		{
			s_cmd->origin = l_cmd[i];
			red_in() = red_origin(l_cmd[i + 1]);
			i += 2;
		}
		else if (l_cmd[i][0] == '>')
		{
			s_cmd->dest = l_cmd[i + 1];
			red_out() = red_dest(l_cmd[i]);
			i += 2;
		}
		else
		{
			if (s_cmd->name == NULL)
				s_cmd->name = find_right_path(l_cmd[i]);
			l_cmd[0] = l_cmd[i];
			l_cmd++;
		}
	}
	l_cmd[0] = NULL;
	return (s_cmd);
}

t_command	**get_command(t_msh *msh, int *i)
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
	s_cmd = init_cmd(msh, cmds);
	return (cmds);
}
