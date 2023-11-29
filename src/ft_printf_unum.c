/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antramir <antramir@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:07:15 by antramir          #+#    #+#             */
/*   Updated: 2022/10/11 12:58:49 by antramir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_to_positive_unum(int num)
{
	unsigned int	uimax;

	uimax = 4294967295;
	if (num == -1)
		return (uimax);
	else
		return (uimax - num + 1);
}

static int	ft_numchar(unsigned int n)
{
	unsigned int	result;

	result = 0;
	if (n == 0)
		return (result + 1);
	while (n > 0)
	{
		n = n / 10;
		result++;
	}
	return (result);
}

static char	*ft_uitoa(unsigned int num)
{
	char	*str;
	int		i;

	str = malloc(sizeof(*str) * ft_numchar(num) + 1);
	if (!str)
		return (NULL);
	i = ft_numchar(num);
	str[i--] = '\0';
	if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		str[i--] = 48 + num % 10;
		num = num / 10;
	}
	return (&str[0]);
}

void	ft_printf_unum(va_list args, int *len)
{
	unsigned int	num;
	char			*str;

	num = va_arg(args, unsigned int);
	if (num < 0)
		num = ft_to_positive_unum(num);
	str = ft_uitoa(num);
	*len += ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
}
