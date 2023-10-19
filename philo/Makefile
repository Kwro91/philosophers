
NAME = philo

CC = gcc

AR = ar rcs

CFLAGS = -Wall -Wextra -Werror -g3

PTHREAD = -pthread

SRC = src/

THREAD = thread/

MUTEX = mutex/

SRCS = $(SRC)philo.c \
	$(SRC)$(THREAD)thread.c \
	$(SRC)$(MUTEX)mutex.c \

OBJ = $(SRCS:.c=.o)

$(NAME) : $(OBJ)
		$(CC) $(PTHREAD) $(CFLAGS) $(OBJ) -o $(NAME)

all : $(NAME)

clean :
		rm -rf $(OBJ)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re