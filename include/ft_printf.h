/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antramir <antramir@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:23:03 by antramir          #+#    #+#             */
/*   Updated: 2022/10/04 14:49:51 by antramir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <limits.h>

int		ft_printf(char const *str, ...);
void	ft_printf_char(va_list args, int *len);
void	ft_printf_string(va_list args, int *len);
void	ft_printf_num(va_list args, int *len);
void	ft_printf_unum(va_list args, int *len);
void	ft_printf_hex(va_list args, int *len, const char format);
void	ft_printf_pointer(va_list args, int *len);

#endif
