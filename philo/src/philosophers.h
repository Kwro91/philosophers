/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:46:53 by besalort          #+#    #+#             */
/*   Updated: 2023/11/06 15:13:40 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_times
{
	struct timeval	start;
	struct timeval	cmp;
	struct timeval	last_meal;
	struct timeval	time_die;
	struct timeval	time_eat;
	struct timeval	time_sleep;
}	t_times;

typedef struct s_philo
{
	pthread_t		tid;
	pthread_mutex_t *l_fork;
	pthread_mutex_t *r_fork;
	pthread_mutex_t eating;
	t_times			time;
	int				indice;
	int				alive;
	int				meal;
	int				meal_max;
	int				philosophers;
	void			*next;
}	t_philo;

typedef struct s_data
{
	t_philo			*philo;
	pthread_mutex_t	fork[200];
	struct timeval	time_die;
	struct timeval	time_eat;
	struct timeval	time_sleep;
	struct timeval	start_time;
	struct timeval	stop_time;
	int				meal_max;
	int				philosophers;
}	t_data;

//Philo.c
void				philo(int ac, char **av);
void				exit_philo(t_data *data);
//Thread
t_philo				*create_philo(t_data *data, int size, int indice);
void				*thread_routine(void *data);
void				end_thread(t_data *data);
int					check_all_ate(t_data *data);
int					check_end(t_data *data);
int					check_out_time(t_philo *philo);
void				print_action(char *action, t_philo *philo);
void				philo_sleep(t_philo *philo);
void				philo_eat(t_philo *philo);
void				philo_think(t_philo *philo);
//Mutex
void				init_all(t_data *data);
void				get_fork(t_data *data, t_philo *philo, int indice);
//Time
int					setup_time(t_data *data);
unsigned long		get_time(t_philo *philo);
unsigned long		get_meal_time(t_philo *philo);
//Verif
int					is_only_number(char **av);
void				max_meal(t_data *data, int ac, char **av);
void				convert_all(t_data *data, char **av);
int					convert_milli_micro(char *time);
int					ft_atoi(char *str);

#endif