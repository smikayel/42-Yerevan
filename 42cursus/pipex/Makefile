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
	@$(AR) $(NAME) $(OBJS)
	@$(CC) $(CFLAGS) $(MAIN) $(NAME) -o $(OUT_PUT)
	@echo "\033[0;92m $(OUT_PUT) done  ✓"
all: $(NAME)

re:	fclean all

clean:
	@$(RM) $(OBJS)
	@echo "\033[0;92m cleaned ✓"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(OUT_PUT)
	@echo "\033[0;92m Fully cleaned ✓"

.PHONY: all clean fclean re