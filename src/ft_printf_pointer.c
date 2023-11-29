/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antramir <antramir@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:53:29 by antramir          #+#    #+#             */
/*   Updated: 2022/10/11 11:59:52 by antramir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static unsigned long long	ft_to_positive_ll(int num)
{
	if (num == -1)
		return (ULLONG_MAX);
	else
		return (ULLONG_MAX - num + 1);
}

static void	ft_hex_selection(uintptr_t num, int *len)
{
	if (num <= 9)
	{
		ft_putchar_fd(num + '0', 1);
		*len += 1;
	}
	else
	{
		ft_putchar_fd(num - 10 + 'a', 1);
		*len += 1;
	}
}

static void	ft_write_hex(uintptr_t num, int *len)
{
	uintptr_t	temp;

	temp = 0;
	if (num >= 16)
	{
		ft_write_hex(num / 16, len);
		ft_write_hex(num % 16, len);
	}
	else
		ft_hex_selection(num, len);
}

static void	ft_printf_phex(va_list args, int *len)
{
	uintptr_t	num;

	num = va_arg(args, uintptr_t);
	if (num == (uintptr_t) NULL)
	{
		*len += write(1, "0", 1);
		return ;
	}
	if (num == 0)
		*len += write(1, "0", 1);
	else if (num < 0)
		num = ft_to_positive_ll(num);
	ft_write_hex(num, len);
}

void	ft_printf_pointer(va_list args, int *len)
{
	*len += write(1, "0x", 2);
	ft_printf_phex(args, len);
}
