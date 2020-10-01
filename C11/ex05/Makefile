# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caubry <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/30 18:58:36 by caubry            #+#    #+#              #
#    Updated: 2020/09/30 22:46:37 by caubry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= srcs/ft_do_op.c \
		  srcs/ft_operateur.c

HEADER	= includes

OBJS	= ${SRCS:.c=.o}

NAME	= do-op

CC		= gcc

FLAGS	= -Wall -Wextra -Werror -I${HEADER}

RM		= rm -f

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${FLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
