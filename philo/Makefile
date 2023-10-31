
NAME = philo

CC = gcc

AR = ar rcs

CFLAGS = -Wall -Wextra -Werror -g3

PTHREAD = -pthread

SRC = src/

THREAD = thread/

MUTEX = mutex/

TIME = time/

VERIF = verif/

SRCS = $(SRC)philo.c \
	$(SRC)$(THREAD)thread.c \
	$(SRC)$(THREAD)action.c \
	$(SRC)$(THREAD)end_thread.c \
	$(SRC)$(MUTEX)mutex.c \
	$(SRC)$(TIME)time.c \
	$(SRC)$(TIME)get_time.c \
	$(SRC)$(VERIF)arg_verif.c \
	$(SRC)$(VERIF)convert.c \
	$(SRC)$(VERIF)ft_atoi.c \

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