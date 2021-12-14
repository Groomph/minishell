/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:27:46 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/13 23:21:19 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

#include <stdio.h> //test



static int	g_char_type[128] = {

	[0] = ERROR,
	[1] = UNPRINT,
	[2] = UNPRINT,
	[3] = UNPRINT,
	[4] = UNPRINT,
	[5] = UNPRINT,
	[6] = UNPRINT,
	[7] = UNPRINT,
	[8] = UNPRINT,
	[10] = UNPRINT,
	[11] = UNPRINT,
	[12] = UNPRINT,
	[13] = UNPRINT,
	[14] = UNPRINT,
	[15] = UNPRINT,
	[16] = UNPRINT,
	[17] = UNPRINT,
	[18] = UNPRINT,
	[19] = UNPRINT,
	[20] = UNPRINT,
	[21] = UNPRINT,
	[22] = UNPRINT,
	[23] = UNPRINT,
	[24] = UNPRINT,
	[25] = UNPRINT,
	[26] = UNPRINT,
	[27] = UNPRINT,
	[28] = UNPRINT,
	[29] = UNPRINT,
	[30] = UNPRINT,
	[31] = UNPRINT,
	[127] = UNPRINT,

	[' '] = BLANK,
	['\t'] = BLANK, /* 9 */

	['|'] = OPERATOR,
	[';'] = OPERATOR,
	['<'] = OPERATOR, 
	['>'] = OPERATOR,

	['"'] = QUOTE,
	['\''] = QUOTE,
		
	['!'] = CHARACTER,
	['#'] = CHARACTER,
	['$'] = CHARACTER,
	['%'] = CHARACTER,
	['&'] = CHARACTER,
	['('] = CHARACTER,
	[')'] = CHARACTER,
	['*'] = CHARACTER,
	['+'] = CHARACTER,
	[','] = CHARACTER,
	['-'] = CHARACTER,
	['.'] = CHARACTER,
	['/'] = CHARACTER,
	['0'] = CHARACTER,
	['1'] = CHARACTER,
	['2'] = CHARACTER,
	['3'] = CHARACTER,
	['4'] = CHARACTER,
	['5'] = CHARACTER,
	['6'] = CHARACTER,
	['7'] = CHARACTER,
	['8'] = CHARACTER,
	['9'] = CHARACTER,
	[':'] = CHARACTER,
	['='] = CHARACTER,
	['?'] = CHARACTER,
	['@'] = CHARACTER,
	['A'] = CHARACTER,
	['B'] = CHARACTER,
	['C'] = CHARACTER,
	['D'] = CHARACTER,
	['E'] = CHARACTER,
	['F'] = CHARACTER,
	['G'] = CHARACTER,
	['H'] = CHARACTER,
	['I'] = CHARACTER,
	['J'] = CHARACTER,
	['K'] = CHARACTER,
	['L'] = CHARACTER,
	['M'] = CHARACTER,
	['N'] = CHARACTER,
	['O'] = CHARACTER,
	['P'] = CHARACTER,
	['Q'] = CHARACTER,
	['R'] = CHARACTER,
	['S'] = CHARACTER,
	['T'] = CHARACTER,
	['U'] = CHARACTER,
	['V'] = CHARACTER,
	['W'] = CHARACTER,
	['X'] = CHARACTER,
	['Y'] = CHARACTER,
	['Z'] = CHARACTER,
	['['] = CHARACTER,
	['\\'] = CHARACTER,
	[']'] = CHARACTER,
	['^'] = CHARACTER,
	['_'] = CHARACTER,
	['`'] = CHARACTER,
	['a'] = CHARACTER,
	['b'] = CHARACTER,
	['c'] = CHARACTER,
	['d'] = CHARACTER,
	['e'] = CHARACTER,
	['f'] = CHARACTER,
	['g'] = CHARACTER,
	['h'] = CHARACTER,
	['i'] = CHARACTER,
	['j'] = CHARACTER,
	['k'] = CHARACTER,
	['l'] = CHARACTER,
	['m'] = CHARACTER,
	['n'] = CHARACTER,
	['o'] = CHARACTER,
	['p'] = CHARACTER,
	['q'] = CHARACTER,
	['r'] = CHARACTER,
	['s'] = CHARACTER,
	['t'] = CHARACTER,
	['u'] = CHARACTER,
	['v'] = CHARACTER,
	['w'] = CHARACTER,
	['x'] = CHARACTER,
	['y'] = CHARACTER,
	['z'] = CHARACTER,
	['{'] = CHARACTER,
	['~'] = CHARACTER
};

/*
 * type 0 = operateur
 * type 1 = quote
 * type 2 = character (everything not above)
 * type 3 = non printable
 * type 4 = blank
 * type 5 = tamere (not supposed to happen)
*/

static int	g_token_type[6] =
{
	TOK_OPERATOR,
	TOK_QUOTED_STR,
	TOK_WORD,
	TOK_ERROR,
	TOK_ERROR,
	TOK_ERROR
};

/*
 * type 0  = operator
 * type 1  = quoted string
 * type 2  = word
 * type 3+ = not handled yet or not supposed to happen
*/

BOOL	get_token_rules(int token_type, char c)
{
	int	char_type;

	char_type = g_char_type[(int) c];
	if (c == '\0' || char_type == ERROR)
		return (FALSE);
	else if (token_type == TOK_QUOTED_STR)
	{
	//	if (char_type == UNPRINT)
	//		return (FALSE);
		return (TRUE);
	}
	else if (token_type == TOK_WORD)
	{
		if (char_type != CHARACTER)
			return (FALSE);
		return (TRUE);
	}
	return (FALSE);
}

/*	TOKEN CONTENT RULES 
 * type -1 = not handled yet or not supposed to happen
 * type 0 (operator): contain only 1 operator or 2 if < or >
 * type 1 (quoted string) = contain anything
 * type 2 (word) = contain caracter, numbers and not operator symbol
*/

int	get_token(char *input)
{
	int	char_type;
	int	token_type;
	int	i;

	char_type = g_char_type[(int) input[0]];
	if (char_type == UNPRINT || char_type == BLANK || char_type == ERROR)
		return (0);
	if (char_type == OPERATOR)
	{
		if ((input[0] == '<' || input[0] == '>')
			&& input[0] == input[1])
			return (2);
		return (1);
	}
	token_type = g_token_type[char_type];
	i = 1;
	while (input[i] && get_token_rules(token_type, input[i]))
	{
		i++;
		if (token_type == TOK_QUOTED_STR && input[0] == input[i - 1])
			break ;
	}
	return (i);
}

void	tokenizer(t_msh *msh, char *input)
{
	int	i;
	char	*token;

	while (input[0])
	{
		while (g_char_type[(int) input[0]] == BLANK)
			input++;
		i = get_token(input);
		if (i > 0)
		{
			token = substr(input, 0, i);
			assert_vector(msh, &(msh->tokens), token);
			input += i;
		}
		else if (input[0])
			input++;
	}
}
