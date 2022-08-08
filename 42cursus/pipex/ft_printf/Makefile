# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvardany <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 21:53:33 by hvardany          #+#    #+#              #
#    Updated: 2022/04/07 21:02:32 by hvardany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CC		=	cc

WALL	=	-Wall -Werror -Wextra -I.

#CFLAGS

LIBFTSRC	=	./libft/libft.a

LIBFT		=	./libft/.c

SRCS	=	ft_printf.c ft_printX.c

RMIF	=	rm -f

OBJ		=	${SRCS:.c=.o}

.c.o: 
	${CC} ${WALL}  -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJ}
			${MAKE} -C ./libft
			cp ./libft/libft.a ${NAME}
			ar -rcs ${NAME} ${OBJ}

clean:		
			${MAKE} clean -C ./libft
		   	${RMIF} ${OBJ}

fclean:		clean
			${MAKE} fclean -C ./libft
			${RMIF} ${NAME}

re:			fclean all

.PHONY:		all clean fclean rm	
