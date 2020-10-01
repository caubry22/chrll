# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caubry <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/26 10:07:35 by caubry            #+#    #+#              #
#    Updated: 2020/09/27 22:29:18 by caubry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c erreur.c ft_de_base.c rush.c printvalue.c doublon.c

OBJS	= ${SRCS:.c=.o}

NAME	= rush-02

CC		= cc

FLAGS	= -Wall -Werror -Wextra

RM		= rm -f

${NAME}:	${OBJS}
			${CC} ${FLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
