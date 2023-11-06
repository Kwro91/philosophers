/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:03:27 by besalort          #+#    #+#             */
/*   Updated: 2023/11/06 17:52:04 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	fill_times(t_data *data, t_philo *philo)
{
	gettimeofday(&philo->time.start, NULL);
	philo->time.last_meal = philo->time.start;
	philo->time.time_die = data->time_die;
	philo->time.time_eat = data->time_eat;
	philo->time.time_sleep = data->time_sleep;
}

t_philo	*create_philo(t_data *data, int size, int indice)
{
	t_philo	*philo;

	philo = NULL;
	if (size > 0)
	{
		philo = malloc(sizeof(t_philo));
		if (!philo)
			return (NULL);
		philo->indice = indice;
		fill_times(data, philo);
		get_fork(data, philo, indice);
		philo->alive = 1;
		philo->meal = 0;
		philo->meal_max = data->meal_max;
		philo->philosophers = data->philosophers;
		pthread_mutex_init(&philo->eating, NULL);
		if (pthread_create(&philo->tid, NULL, thread_routine,
				(void *)philo) != 0)
			exit_philo(data);
		philo->next = create_philo(data, size - 1, indice + 1);
		if (philo->next == NULL && (size -1) > 0)
			return (free(philo), NULL);
	}
	return (philo);
}

void	*thread_routine(void *my_philo)
{
	t_philo	*philo;

	philo = (t_philo *)my_philo;
	if (!philo)
		return (NULL);
	if (philo->indice %2)
		usleep(15000);
	while (philo->alive != 0)
	{
		// if (check_out_time(philo) == 1)
		// {
		// 	philo->alive = 0;
		// 	return (NULL);
		// }
		if (philo->meal_max > 0 && philo->meal >= philo->meal_max)
			return (NULL);
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}
