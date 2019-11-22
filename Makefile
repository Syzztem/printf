# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lothieve <lothieve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/06 15:35:45 by lothieve          #+#    #+#              #
#    Updated: 2019/11/21 17:10:28 by lothieve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c ft_isalnum.c ft_printf.c ft_putnbr_base_f.c print_functions.c ft_isalnum.c

INCLUDES = includes

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

CC = clang

RM = rm -rf

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCLUDES}

$(NAME):	${OBJS}
			ar rcs ${NAME} ${OBJS}


clean:		
			${RM} ${OBJS} ${OBJB}

fclean:		clean
			${RM} ${NAME} 

re:			fclean all

.PHONY:		all clean fclean re
