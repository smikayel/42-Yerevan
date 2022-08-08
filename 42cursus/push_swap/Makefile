# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 12:24:19 by smikayel          #+#    #+#              #
#    Updated: 2022/08/08 12:43:46 by smikayel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

OBJS_DIR = objs

SRCS_DIR = src

FLAGS =  -Wall -Werror -Wextra -g -Iincludes

SRCS = $(wildcard $(SRCS_DIR)/*.c)

OBJS = $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

RM = rm -rf

MKDIR = mkdir -p

.DEFAULT_GOAL = all

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJS_DIR):
	$(MKDIR) $(OBJS_DIR)

all: $(NAME)

$(NAME): $(OBJS) | $(OBJS_DIR)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LINKERS)
	@echo "\n\n-----------------Norminette-------------\n"
	norminette
	@echo "----------------------------------------\n"

bonus: all

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

push:
	@git add .
	@git commit -m "$m"
	@git push

.PHONY: all clean fclean re bonus push