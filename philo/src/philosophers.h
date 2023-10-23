/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:46:53 by besalort          #+#    #+#             */
/*   Updated: 2023/10/23 16:51:51 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t	tid;
	int			indice;
	int			alive;
	void		*next;
}	t_philo;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				indice;
	void			*next;
}	t_fork;

typedef struct s_data
{
	t_philo			*philo;
	t_fork			*fork;
	struct timeval	time_die;
	struct timeval	time_eat;
	struct timeval	time_sleep;
	struct timeval	start_time;
	struct timeval	stop_time;
}	t_data;

//Philo.c
void	philo(char **av);
//Thread
t_philo	*create_philo(t_data *data, int size, int indice);
void	*thread_routine(void *data);
int		thread_end(t_data *data);
void	philo_sleep(t_data *data);
//Mutex
t_fork	*create_fork(int size, int indice);
//Time
int		setup_time(t_data *data);
//Verif
int		is_only_number(char **av);
void	convert_all(t_data *data, char **av);
void	convert_die(t_data *data, char *time);
void	convert_eat(t_data *data, char *time);
void	convert_sleep(t_data *data, char *time);
char	*invert_tab(char *tab);

#endif