/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:05:36 by besalort          #+#    #+#             */
/*   Updated: 2023/11/16 13:29:29 by besalort         ###   ########.fr       */
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

void	set_values(t_data *data, t_philo *philo)
{
	philo->alive = 1;
	philo->dead = &data->dead;
	philo->meal = 0;
	philo->meal_max = data->meal_max;
	philo->philosophers = data->philosophers;
	philo->print = &data->print;
	philo->is_dead = &data->is_dead;
	pthread_mutex_init(&philo->eating, NULL);
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
		set_values(data, philo);
		if (pthread_create(&philo->tid, NULL, thread_routine,
				(void *)philo) != 0)
			exit_philo(data);
		philo->next = create_philo(data, size - 1, indice + 1);
		if (philo->next == NULL && (size -1) > 0)
			return (free(philo), NULL);
	}
	return (philo);
}
