
NAME = philo

CC = gcc

AR = ar rcs

CFLAGS = -Wall -Wextra -Werror -g3

PTHREAD = -pthread

SRC = src/

THREAD = thread/

MUTEX = mutex/

VERIF = verif/

SRCS = $(SRC)philo.c \
	$(SRC)$(THREAD)thread.c \
	$(SRC)$(THREAD)time.c \
	$(SRC)$(MUTEX)mutex.c \
	$(SRC)$(VERIF)arg_verif.c \
	$(SRC)$(VERIF)convert.c \

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