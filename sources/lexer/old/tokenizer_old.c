/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:27:46 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/12 19:01:21 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h> //test

/*
 * type -1 = tamere (not supposed to happen)
 * type 0 = non printable
 * type 1 = blank
 * type 2 = operateur
 * type 3 = quote
 * type 4 = character (everything not above)
*/

int	get_char_type(char c)
{
	if (c < 32 || c == 127)
		return (0);
	else if (is_whitespace(c))
		return (1);
	else if (c == '|' || c == ';'
			|| c == '<' || c == '>')
		return (2);
	else if (c == '\'' || c == '"')
		return (3);
	else if (c > 32 && c < 127) 
		return (4);
	return (-1);
}

/*
 * type -1 = not handled yet or not supposed to happen
 * type 0  = operator
 * type 1  = quoted string
 * type 2  = word
*/

int	get_token_type(int char_type)
{
	if (char_type == 0 || char_type == 1 || char_type == -1)
		return (-1);
	if (char_type == 2)
		return (0);
	if (char_type == 3)
		return (1);
	if (char_type == 4)
		return (2);
}

/*	TOKEN CONTENT RULES 
 * type -1 = not handled yet or not supposed to happen
 * type 0 (operator): contain only 1 operator or 2 if < or >
 * type 1 (quoted string) = contain anything
 * type 2 (word) = contain caracter, numbers and not operator symbol
*/

BOOL	get_token_rules(int token_type, char c)
{
	int	char_type;

	if (c == '\0')
		return (FALSE);
	if (token_type == -1)
		return (-1);
	else if (token_type == 0)
		return (FALSE);
	else if (token_type == 1)
	{
		char_type = get_char_type(c);
		if (c == 0)
			return (FALSE)
		return (TRUE);
	}
	else if (token_type == 2)
	{
		char_type = get_char_type(c);
		if (c != 4)
			return (FALSE)
		return (TRUE);
	}
}

int	get_token(char *input)
{
	int	i;
	int	char_type;
	int	token_type;

	i = 1;
	char_type = get_char_type(input[0]);
	if (char_type == 0 || char_type == 1 || char_type == 5)
	{
		if (char_type == 1)
			printf("get_token: type 1 not supposed to happen\n");
		if (char_type == 5)
			printf("get_token: type 5 not supposed to happen\n");
		return (0);
	}
	if (char_type == 1)
	{
		if ((input[0] == '<' || input[0] == '>')
			&& input[0] == input[1])
			return (2);
		return (1);
	}
	token_type = get_token_type(char_type);
	while (input[i] && get_token_rules(token_type, input[i]))
	{
		i++;
	}
	return (i);
}

void	tokenizer(char *input)
{
	int	i;
	char	*token;

	while (!is_closed_quote(input));
		input = complete_input(input);
	while (*input)
	{
		while (is_whitespace(input[0]))
			input++;
		i = get_token(input);
		if (i > 0)
		{
			token = substr(input, 0, i);
			input += i;
			printf("%s§\n", token);
			free(token);
		}
		else
			input++;
	}
}
