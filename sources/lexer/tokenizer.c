/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:27:46 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/20 12:07:56 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "lexer.h"

int	specific_rules(char *input, int token_type, int i)
{
	if (token_type == TOK_QUOTED_STR || token_type == TOK_WORD)
	{
		token_type = get_token_type(get_char_type(input[i]));
		if (token_type == TOK_QUOTED_STR || token_type == TOK_WORD)
			return (get_token(&input[i]));
	}
	return (0);
}

int	get_token(char *input)
{
	int	char_type;
	int	token_type;
	int	i;

	char_type = get_char_type(input[0]);
	token_type = get_token_type(char_type);
	i = 1;
	char_type = get_char_type(input[i]);
	while (input[i] && is_allowed(char_type, token_type))
	{
		i++;
		if (token_type == TOK_QUOTED_STR && input[0] == input[i - 1])
			break ;
		char_type = get_char_type(input[i]);
	}
	return (i + specific_rules(input, token_type, i));
}

void	tokenizer(t_msh *msh, char *input)
{
	int		i;
	char	*token;

	while (input[0])
	{
		while (get_token_type(get_char_type(input[0])) == NOT_A_TOKEN)
			input++;
		i = get_token(input);
		if (i > 0)
		{
			token = substr(input, 0, i);
			token = assert_gc(msh, token, free);
			assert_bool(msh, vector_add(&(msh->tokens), token));
			input += i;
		}
		else if (input[0])
			input++;
	}
}
