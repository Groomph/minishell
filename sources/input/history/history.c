/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:09:38 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/17 22:00:59 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <input.h>

int	is_present(t_vector *history, t_vecstr *input)
{
	int	i;

	i = 0;
	while (i < history->size)
	{
		if (input == history->arr[i])
			return (i);
		i++;
	}
	return (-1);
}

void	add_to_history(t_msh *msh, t_vecstr *input)
{
	int			i;
	t_vector	*tmp;

	if (input->size > 0)
	{
		i = is_present(&(msh->history), input);
		if (i == -1)
			assert_bool(msh, vector_add(&(msh->history), input));
		else
		{
			tmp = vector_extract(&(msh->history), i);
			assert_malloc(msh, tmp);
			assert_bool(msh, vector_add(&(msh->history), tmp));
		}	
	}
}
