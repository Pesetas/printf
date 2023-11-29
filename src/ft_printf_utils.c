/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antramir <antramir@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:28:48 by antramir          #+#    #+#             */
/*   Updated: 2022/10/11 00:08:08 by antramir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_printf_char(va_list args, int *len)
{
	ft_putchar_fd((char)va_arg(args, int), 1);
	*len += 1;
}

void	ft_printf_string(va_list args, int *len)
{
	char	*string;
	int		i;

	i = 0;
	string = va_arg(args, char *);
	if (string == NULL)
	{
		write(1, "(null)", 6);
		*len += 6;
	}
	else
	{
		while (string[i])
			write(1, &string[i++], 1);
		*len += i;
	}
}

void	ft_printf_num(va_list args, int *len)
{
	int		num;
	char	*str;

	num = va_arg(args, int);
	str = ft_itoa(num);
	*len += ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
}
