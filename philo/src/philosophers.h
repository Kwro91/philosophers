#include <unistd.h>
#include <stdio.h>

typedef struct s_philo
{
	int		indice;
	int		left;
	int		right;
	void	*next;
}	t_philo;

typedef struct s_fork
{
	int		indice;
	int		position;
	void	*next;
}	t_fork;

typedef struct s_data
{
	t_philo		*philo;
	t_fork		*fork;
}	t_data;