/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 19:05:47 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/03 21:13:11 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "lexer.h"

int	expand_exitstate(t_msh *msh, t_vecstr *string, int i)
{
	char	buff[20];
	int		size;
	int		i2;

	vecstr_delone(string, i, 2);
	size = itoa_base(msh->exit_state, buff, "0123456789", 10);
	i2 = 0;
	while (buff[i2])
	{
		if (vecstr_insert(string, i, buff[i2]))
			i++;
		i2++;
	}
	return (i);
}

int	expand_var(t_msh *msh, t_vecstr *string, int i)
{
	char	*var;
	int		i2;
	char	*content;
	char	tmp;

	var = &(string->arr[i]);
	i2 = 1;
	while (is_alphanum(var[i2]))
		i2++;
	tmp = var[i2];
	var[i2] = '\0';
	content = get_env(msh, &(var[1]));
	var[i2] = tmp;
	vecstr_delone(string, i, i2);
	if (!content)
		return (i);
	i2 = 0;
	while (content[i2])
	{
		if (vecstr_insert(string, i, content[i2]))
			i++;
		i2++;
	}
	return (i);
}

static int	skip_trim_singlequote(t_vecstr *string, int i)
{
	char	*str;

	str = string->arr;
	if (str[i] == '\'')
		vecstr_delone(string, i, 1);
	while (str[i] && str[i] != '\'')
		i++;
	if (str[i] == '\'')
		vecstr_delone(string, i, 1);
	return (i);
}

static void	trim_expand(t_msh *msh, t_vecstr *string)
{
	char	*str;
	int		i;
	BOOL	dquote;

	str = string->arr;
	i = 0;
	dquote = FALSE;
	while (str[i])
	{
		if (!dquote && str[i] == '\'')
			i = skip_trim_singlequote(string, i);
		else if (str[i] == '"')
		{
			vecstr_delone(string, i, 1);
			dquote = !dquote;
		}
		else if (str[i] == '$' && is_alphanum(str[i + 1]))
			i = expand_var(msh, string, i);
		else if (str[i] == '$' && str[i + 1] == '?')
			i = expand_exitstate(msh, string, i);
		else
			i++;
		str = string->arr;
	}
}

char	*trim_expand_var(t_msh *msh, char *str)
{
	t_vecstr	*string;
	int			i;
	BOOL		check;

	i = 0;
	check = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"' || str[i] == '$')
			check++;
		i++;
	}
	if (check == 0)
		return (str);
	string = vecstr_newfromstr(str);
	if (!string)
		return (NULL);
	assert_gc(msh, string, (void *)(void *)vecstr_clear);
	trim_expand(msh, string);
	return (string->arr);
}
