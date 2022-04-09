NAME = bsq

SRC =	srcs/main.c srcs/fonctions.c \
		srcs/ft_start.c \
		srcs/ft_check_instructions.c \
		srcs/ft_board.c \
		srcs/ft_optimisations.c \
		srcs/functions.c

all: $(NAME)

$(NAME):
		gcc -Wall -Wextra -Werror -o $(NAME) $(SRC)
clean:
		/bin/rm -f
fclean: clean
		/bin/rm -f $(NAME)
re: fclean all
