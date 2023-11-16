/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:03:27 by besalort          #+#    #+#             */
/*   Updated: 2023/11/16 16:34:56 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*thread_routine(void *my_philo)
{
	t_philo	*philo;

	philo = (t_philo *)my_philo;
	if (!philo)
		return (NULL);
	pthread_mutex_lock(philo->is_dead);
	while (*philo->dead == 0)
	{
		pthread_mutex_unlock(philo->is_dead);
		if (philo->philosophers == 1)
		{
			usleep(philo->time.time_die);
			return (NULL);
		}
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
		pthread_mutex_lock(philo->is_dead);
	}
	pthread_mutex_unlock(philo->is_dead);
	return (NULL);
}
