# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 20:10:50 by smikayel          #+#    #+#              #
#    Updated: 2022/07/26 17:39:38 by smikayel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MINILIBIX = ./libmlx.dylib

PRINTF = ./libftprintf.a

NAME = so_long

SRCS =	./sources/*c ./*c

CC = cc

FLAGS = -Wall -Wextra -Werror

OUTPUT = -o $(NAME)

all :
	@make -C ./ft_printf
	@make -C ./minilibx_mms_20200219
	@cp ft_printf/libftprintf.a ./libftprintf.a
	@cp minilibx_mms_20200219/libmlx.dylib $(MINILIBIX)
	@$(CC) $(FLAGS) $(MINILIBIX) $(PRINTF) $(SRCS) $(OUTPUT)
	@echo "\033[0;92m $(NAME) Done, Have a good game! ✓"

clean :
	@make clean -C ./ft_printf
	@make clean -C ./minilibx_mms_20200219
	@echo "\033[0;92m cleaned ✓"

fclean :
	@$(clean)
	@make fclean -C ./ft_printf
	@rm -rf ./minilibx_mms_20200219/$(MINILIBIX)
	@rm -rf $(NAME)
	@rm -rf $(MINILIBIX)
	@rm -rf libftprintf.a
	@echo "\033[0;92m Fully cleaned ✓"

re : fclean all
