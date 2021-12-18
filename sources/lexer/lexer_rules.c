/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_rules.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:27:46 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/18 13:59:27 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lexer.h"

static const int	g_char_type[128] = {
[0] = IGNORE,
[1] = IGNORE,
[2] = IGNORE,
[3] = IGNORE,
[4] = IGNORE,
[5] = IGNORE,
[6] = IGNORE,
[7] = IGNORE,
[8] = IGNORE,
[11] = IGNORE,
[12] = IGNORE,
[13] = IGNORE,
[14] = IGNORE,
[15] = IGNORE,
[16] = IGNORE,
[17] = IGNORE,
[18] = IGNORE,
[19] = IGNORE,
[20] = IGNORE,
[21] = IGNORE,
[22] = IGNORE,
[23] = IGNORE,
[24] = IGNORE,
[25] = IGNORE,
[26] = IGNORE,
[27] = IGNORE,
[28] = IGNORE,
[29] = IGNORE,
[30] = IGNORE,
[31] = IGNORE,
[127] = IGNORE,
	/////////////////////        
[10] = BLANK,
[' '] = BLANK,
['\t'] = BLANK, /* 9 */
	/////////////////////        
['|'] = OPERATOR,
[';'] = OPERATOR,
['<'] = OPERATOR,
['>'] = OPERATOR,
	/////////////////////        
['"'] = QUOTE,
['\''] = QUOTE,
	/////////////////////        
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

static const int	g_token_type[CHAR_NB] = {
[OPERATOR] = TOK_OPERATOR,
[QUOTE] = TOK_QUOTED_STR,
[CHARACTER] = TOK_WORD,
[BLANK] = NOT_A_TOKEN,
[IGNORE] = NOT_A_TOKEN
};

/*
 * type 0  = operator
 * type 1  = quoted string
 * type 2  = word
 * type 3+ = not handled yet or not supposed to happen
 */

static const BOOL	g_token_rules[TOK_NB][CHAR_NB] = {
	/////////////////////        
[TOK_OPERATOR] = {
	//
[OPERATOR] = TRUE,
[QUOTE] = FALSE,
[CHARACTER] = FALSE,
[BLANK] = FALSE,
[IGNORE] = FALSE
},
	/////////////////////        
[TOK_QUOTED_STR] = {
	//
[OPERATOR] = TRUE,
[QUOTE] = TRUE,
[CHARACTER] = TRUE,
[BLANK] = TRUE,
[IGNORE] = FALSE
},
	/////////////////////        
[TOK_WORD] = {
	//
[OPERATOR] = FALSE,
[QUOTE] = TRUE,
[CHARACTER] = TRUE,
[BLANK] = FALSE,
[IGNORE] = FALSE
},
	/////////////////////        
[NOT_A_TOKEN] = {
	//
[OPERATOR] = FALSE,
[QUOTE] = FALSE,
[CHARACTER] = FALSE,
[BLANK] = FALSE,
[IGNORE] = FALSE
}
};

/*
BOOL	get_token_rules(int token_type, char c)
{
	int	char_type;

	char_type = g_char_type[(int) c];
	if (c == '\0' || char_type == ERROR)
		return (FALSE);
	else if (token_type == TOK_QUOTED_STR)
	{
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
*/

/*	TOKEN CONTENT RULES 
 * type -1 = not handled yet or not supposed to happen
 * type 0 (operator): contain only 1 operator or 2 if < or >
 * type 1 (quoted string) = contain anything
 * type 2 (word) = contain caracter, numbers and not operator symbol
 */

int	get_char_type(int c)
{
	if (c < 0 || c > 127)
		return (IGNORE);
	return (g_char_type[c]);
}

int	get_token_type(int char_type)
{
	return (g_token_type[char_type]);
}

BOOL	is_allowed(int char_type, int token_type)
{
	return (g_token_rules[token_type][char_type]);
}
