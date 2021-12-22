/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:08:54 by aldamien          #+#    #+#             */
/*   Updated: 2021/12/22 16:40:45 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "lexer.h"
#include "libft.h"

BOOL	is_operator_valid(char *token)
{
	// si token[1] == 0, alors quel que soit l'operateur initial, c'est tout bon !
	if (token[1] == 0)
		return (1);
	else if (token[0] == '>' && token[1] == '>' && token[2] == 0)
		return (1);
	else if (token[0] == '<' && token[1] == '<' && token[2] == 0)
		return (1);
	printf("syntax error : token %s unknown operator.\n", token);
	return (0);
}

BOOL	syntax_operator(char **tokens, int *i)
{
	if (!is_operator_valid(tokens[*i]))
		return (0);
	if (tokens[0][0] == '|' || tokens[1] == NULL)
		return (0);
	if (tokens[*i][0] == '<' && get_char_type(tokens[(*i) - 1][0]) != OPERATOR)
		return (1);
	if (tokens[*i][0] == '>' && get_char_type(tokens[(*i) + 1][0]) != OPERATOR)
		return (1);
	if (tokens[*i][0] == '|' && tokens[*i][1] == 0)
		return (1);
	printf("syntax error : unexpected token near operator.\n");
	return (0);
}

int	check_syntax(t_msh *msh)
{
	char	**tokens;
	int	i;

	i = 0;
	tokens = (char **)msh->tokens.arr;
	while (tokens[i])
	{
		if (get_char_type(tokens[i][0]) == OPERATOR && !(syntax_operator(tokens, &i)))
		{
			printf("test bien chiant\n");
			return (0);
		}
/*		else if (get_char_type(tokens[i][0]) == CHARACTER && !syntax_word(tokens, i))
			return (0)
		else if (get_char_type(tokens[i][0]) == QUOTE && !syntax_quote, &i)
			return (0)
*/		i++;
	}
	return (1);
}
