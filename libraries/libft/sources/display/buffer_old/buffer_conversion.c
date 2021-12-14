/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 07:28:28 by rsanchez          #+#    #+#             */
/*   Updated: 2021/09/10 21:19:05 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"
#include "libft.h"

void	write_widechar_buffer(wchar_t c)
{
	if (c <= 0x7F)
		write_char_buffer(c, 1);
	else if (c <= 0x7FF)
	{
		write_char_buffer((c >> 6) + 0xC0, 1);
		write_char_buffer((c & 0x3F) + 0x80, 1);
	}
	else if (c <= 0xFFFF)
	{
		write_char_buffer((c >> 12) + 0xE0, 1);
		write_char_buffer(((c >> 6) & 0x3F) + 0x80, 1);
		write_char_buffer((c & 0x3F) + 0x80, 1);
	}
	else if (c <= 0x10FFFF)
	{
		write_char_buffer((c >> 18) + 0xF0, 1);
		write_char_buffer(((c >> 12) & 0x3F) + 0x80, 1);
		write_char_buffer(((c >> 6) & 0x3F) + 0x80, 1);
		write_char_buffer((c & 0x3F) + 0x80, 1);
	}
}

void	write_int_buffer(int nb)
{
	char	str[12];
	int		size;

	size = itoa_base(nb, str, "0123456789", 10);
	write_str_buffer(str, size);
}
