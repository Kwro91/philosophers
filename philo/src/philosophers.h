#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct s_philo
{
	pthread_t	tid;
	int			indice;
	void		*next;
}	t_philo;

typedef struct s_fork
{
	pthread_mutex_t fork;
	int		indice;
	void	*next;
}	t_fork;

typedef struct s_data
{
	t_philo		*philo;
	t_fork		*fork;
}	t_data;

//Philo.c
void	philo(char **av);
//Thread
t_philo	*create_philo(t_data *data, int size, int indice);
void	*thread_routine(void *data);
int		thread_end(t_data *data);
//Mutex
t_fork	*create_fork(int size, int indice);