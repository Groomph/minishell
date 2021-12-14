/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 07:28:28 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/10 18:08:09 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"

void	buffer_widechar(t_buff *buff, wchar_t c)
{
	if (c <= 0x7F)
		buffer_char(buff, c, 1);
	else if (c <= 0x7FF)
	{
		buffer_char(buff, (c >> 6) + 0xC0, 1);
		buffer_char(buff, (c & 0x3F) + 0x80, 1);
	}
	else if (c <= 0xFFFF)
	{
		buffer_char(buff, (c >> 12) + 0xE0, 1);
		buffer_char(buff, ((c >> 6) & 0x3F) + 0x80, 1);
		buffer_char(buff, (c & 0x3F) + 0x80, 1);
	}
	else if (c <= 0x10FFFF)
	{
		buffer_char(buff, (c >> 18) + 0xF0, 1);
		buffer_char(buff, ((c >> 12) & 0x3F) + 0x80, 1);
		buffer_char(buff, ((c >> 6) & 0x3F) + 0x80, 1);
		buffer_char(buff, (c & 0x3F) + 0x80, 1);
	}
}

void	buffer_int(t_buff *buff, int nb)
{
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			buffer_str(buff, "-2147483648", 11);
			return ;
		}
		buffer_char(buff, '-', 1);
		nb *= -1;
	}
	if (nb >= 10)
		buffer_int(buff, nb / 10);
	buffer_char(buff, (nb % 10) + '0', 1);
}

void	buffer_longint(t_buff *buff, long int nb)
{
	if (nb < 0)
	{
		if (nb < -9223372036854775807)
		{
			buffer_str(buff, "-9223372036854775808", 20);
			return ;
		}
		buffer_char(buff, '-', 1);
		nb *= -1;
	}
	if (nb >= 10)
		buffer_longint(buff, nb / 10);
	buffer_char(buff, (nb % 10) + '0', 1);
}
