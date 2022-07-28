# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvardany <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 19:17:29 by hvardany          #+#    #+#              #
#    Updated: 2022/04/07 21:00:59 by hvardany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS	= ft_atoi.c ft_strlen.c ft_itoa.c

OBG	= ${SRCS:.c=.o}

NAME	= libft.a

CC		= cc

WALL	= -Wall -Werror -Wextra -I.

RMIF		= rm -f

.c.o:
	${CC} ${WALL} -c $< -o ${<:.c=.o}

${NAME}:	${OBG}
			ar rcs ${NAME} ${OBG}

all:		${NAME}

clean:
			${RMIF} ${OBG}

fclean:		clean
			${RMIF}	${NAME}

bonus:		${NAME}

re:			fclean all

.PHONY:		all clean fclean re
