/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antramir <antramir@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:57:43 by antramir          #+#    #+#             */
/*   Updated: 2022/10/11 14:32:55 by antramir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_identify_arg(const char *str, va_list args, int pos, int *len)
{
	if (str[pos] == '%')
		*len += write(1, "%", 1);
	else if (str[pos] == 'c')
		ft_printf_char(args, len);
	else if (str[pos] == 's')
		ft_printf_string(args, len);
	else if (str[pos] == 'd' || str[pos] == 'i')
		ft_printf_num(args, len);
	else if (str[pos] == 'u')
		ft_printf_unum(args, len);
	else if (str[pos] == 'x' || str[pos] == 'X')
		ft_printf_hex(args, len, str[pos]);
	else if (str[pos] == 'p')
		ft_printf_pointer(args, len);
	return ;
}

static void	ft_printf_sub(va_list args, char const *str, int *len)
{
	int	pos;

	pos = 0;
	while (str[pos])
	{
		if (str[pos] == '%')
		{
			pos++;
			ft_identify_arg(str, args, pos, len);
		}
		else
			*len += write(1, &(str[pos]), 1);
		if (!str)
		{
			write(1, "(null)", 6);
			va_end(args);
			return ;
		}
		pos++;
	}
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		len;

	if (!str)
		return (-1);
	va_start (args, str);
	len = 0;
	ft_printf_sub(args, str, &len);
	va_end(args);
	return (len);
}
