/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_old.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:27:46 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/12 15:45:10 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

int	get_char_type(char c)
{
	if (c < 32 || c == 127)
		return (0);
	else if (c == '|' || c == ';'
			|| c == '"' || c == '\'' || c == '`'
			|| c == '<' || c == '>')
		return (1);
	else if (is_whitespace(c))
		return (2);
	else if (c > 32 && c < 127) 
		return (3);
	return (4);
}

int	get_token(char *input)
{
	int	i;
	int	type;

	i = 1;
	type = get_char_type(input[0]);
	if (type == 1)
	{
		if ((input[0] == '<' || input[0] == '>')
			&& input[0] == input[1])
			return (2);
		return (1);
	}
	while (input[i] && get_char_type(input[i]) == type)
	{
		i++;
	}
	return (i);
}

void	tokenizer(char *input)
{
	int	i;
	char	*token;

	while (*input)
	{
		while (is_whitespace(input[0]))
			input++;
		i = get_token(input);
		token = substr(input, 0, i);
		input += i;
		printf("%s§\n", token);
		free(token);
	}
}
