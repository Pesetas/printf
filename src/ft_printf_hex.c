/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antramir <antramir@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 00:05:47 by antramir          #+#    #+#             */
/*   Updated: 2022/10/11 00:09:19 by antramir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_hex_selection(unsigned int num, int *len, const char format)
{
	if (num <= 9)
	{
		ft_putchar_fd(num + '0', 1);
		*len += 1;
	}
	else
	{
		if (format == 'x')
		{
			ft_putchar_fd(num - 10 + 'a', 1);
			*len += 1;
		}
		if (format == 'X')
		{
			ft_putchar_fd(num - 10 + 'A', 1);
			*len += 1;
		}
	}
}

static void	ft_write_hex(unsigned int num, int *len, const char format)
{
	unsigned int	temp;

	temp = 0;
	if (num >= 16)
	{
		ft_write_hex(num / 16, len, format);
		ft_write_hex(num % 16, len, format);
	}
	else
		ft_hex_selection(num, len, format);
}

void	ft_printf_hex(va_list args, int *len, const char format)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	if (num == 0)
		*len += write(1, "0", 1);
	else
		ft_write_hex(num, len, format);
}
