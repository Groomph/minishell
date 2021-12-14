/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_old.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:30:16 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/10 18:07:08 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_OLD_H
# define BUFFER_OLD_H

# include <unistd.h>
# include <wchar.h>

# define BUFFER_SIZE 100

typedef struct s_buffer
{
	int			i;
	int			totalsize;
	char		str[BUFFER_SIZE];
}				t_buffer;

typedef struct s_buffer2
{
	char		*str;
	int			size;
	int			i;
	char		*cursor;
}				t_buffer2;

int				print_buffer(int fd);
void			write_str_buffer(const char *str, int size);
void			write_char_buffer(char c, int nb);
void			write_int_buffer(int nb);
void			write_widechar_buffer(wchar_t c);
void			init_buffer(void);

#endif
