/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:22:48 by romain            #+#    #+#             */
/*   Updated: 2021/12/13 20:06:57 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static BOOL	is_quote(char c)
{
	if (c == '\'' || c == '"')
		return (TRUE);
	return (FALSE);
}

BOOL	is_closed_quote(char *input)
{
	int	i;
	char	quote;

	i = 0;
	quote = 0;
	while (input && input[i])
	{
		if (!quote && is_quote(input[i]))
			quote = input[i];
		else if (quote && quote == input[i])
			quote = 0;
		i++;
	}
	if (quote)
		return (FALSE);
	return (TRUE);
}
