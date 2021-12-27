/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 19:05:47 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/27 11:25:04 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

static int	expand_var(t_msh *msh, t_vecstr *string, int i)
{
	(void)msh;
	(void)string;
	return (i + 1);
}

char	*expand_heredoc(t_msh *msh, char *str)
{
	int			i;
	BOOL		check;
	t_vecstr	*string;

	i = -1;
	check = 0;
	while (str[++i])
	{
		if (str[i] == '$')
			check++;
	}
	if (check == 0)
		return (str);
	string = vecstr_newfromstr(str);
	assert_gc(msh, string, (void *)(void *)vecstr_clear);
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			i = expand_var(msh, string, i);
		else
			i++;
	}
	return (string->arr);
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
		else if (str[i] == '$')
			i = expand_var(msh, string, i);
		else
			i++;
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
