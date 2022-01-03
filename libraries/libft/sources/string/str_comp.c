/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_comp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:27:17 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/26 19:04:55 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_comp(const char *str, const char *str2)
{
	int					i;
	const unsigned char	*s;
	const unsigned char	*s2;

	s = (const unsigned char *)str;
	s2 = (const unsigned char *)str2;
	i = 0;
	while (s[i] == s2[i])
	{
		i++;
		if (s[i] == '\0')
			return (s[i] - s2[i]);
	}
	return (s[i] - s2[i]);
}
