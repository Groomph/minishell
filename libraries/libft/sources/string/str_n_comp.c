/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_n_comp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:27:17 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/16 02:59:55 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_n_comp(const char *str, const char *str2, int stop)
{
	int	i;

	if (stop == 0)
		return (0);
	i = 0;
	while (str[i] && str[i] == str2[i] && stop)
	{
		i++;
		stop--;
	}
	if (!stop)
		return (0);
	return (str[i] - str2[i]);
}
