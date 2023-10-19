
NAME = philo

CC = gcc

AR = ar rcs

CFLAGS = -Wall -Wextra -Werror

SRC = ./src/philo.c \

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all : $(NAME)

clean :
		rm -rf $(OBJ)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re