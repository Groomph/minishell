/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:30:16 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/10 17:43:01 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_H
# define BUFFER_H

# include <wchar.h>

# define BUFFER_SIZE 1024

typedef struct s_buffer
{
	int			i;
	int			totalsize;
	char		str[BUFFER_SIZE];
}				t_buff;

int				buffer_print(t_buff *buff, int fd);
void			buffer_init(t_buff *buff);
void			buffer_str(t_buff *buff, const char *str, int size);
void			buffer_char(t_buff *buff, char c, int nb);
void			buffer_widechar(t_buff *buff, wchar_t c);
void			buffer_int(t_buff *buff, int nb);
void			buffer_longint(t_buff *buff, long int nb);

#endif
