SRCS = $(wildcard ./src/*.c)

OUT_PUT = pipex

MAIN = pipex.c

NAME = pipex.a

RM = rm -rf

AR = ar rcs

CC	= cc
CFLAGS =  
# CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	@make -C ./ft_printf
	@cp ft_printf/libftprintf.a ./libftprintf.a	
	@$(AR) $(NAME) $(OBJS)
	@$(CC) $(CFLAGS) $(MAIN) $(NAME) ./libftprintf.a -o $(OUT_PUT)
	@echo "\033[0;92m $(OUT_PUT) done  ✓"
all: $(NAME)

re:	fclean all

clean:
	@make clean -C ./ft_printf
	@$(RM) $(OBJS)
	@echo "\033[0;92m cleaned ✓"

fclean: clean
	@make fclean -C ./ft_printf
	@rm -rf libftprintf.a
	@$(RM) $(NAME)
	@$(RM) $(OUT_PUT)
	@echo "\033[0;92m Fully cleaned ✓"

.PHONY: all clean fclean re