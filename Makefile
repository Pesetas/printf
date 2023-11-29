# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antramir <antramir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/19 11:06:31 by antramir          #+#    #+#              #
#    Updated: 2022/05/31 11:48:38 by antramir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT 			= ./libft/libft.a

NAME			= libftprintf.a

SRCS			= src/ft_printf.c \
				src/ft_printf_hex.c \
				src/ft_printf_utils.c \
				src/ft_printf_pointer.c \
				src/ft_printf_unum.c

OBJS			=	ft_printf.o \
				ft_printf_hex.o \
				ft_printf_utils.o \
				ft_printf_pointer.o \
				ft_printf_unum.o

CC				= gcc

RM				= rm -f

CFLAGS			= -c -Wall -Wextra -Werror

${NAME}:
			$(MAKE) bonus -C ./libft
			cp libft/libft.a $(NAME)
			${CC} ${CFLAGS} ${SRCS}
			ar crs ${NAME} ${OBJS}

all:		${NAME}

clean:
			$(MAKE) clean -C ./libft
			${RM} ${OBJS}

fclean:		clean
			$(MAKE) fclean -C ./libft
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
