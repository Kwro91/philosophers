/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:03:27 by besalort          #+#    #+#             */
/*   Updated: 2023/11/13 14:50:36 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*thread_routine(void *my_philo)
{
	t_philo	*philo;

	philo = (t_philo *)my_philo;
	if (!philo)
		return (NULL);
	while (*philo->dead == 0)
	{
		if (philo->philosophers == 1)
		{
			usleep(philo->time.time_die.tv_usec);
			return (NULL);
		}
		// printf("%i va manger dead = %i\n", philo->indice, *philo->dead);
		philo_eat(philo);
		// printf("%i va dormir dead = %i\n", philo->indice, *philo->dead);
		philo_sleep(philo);
		// printf("%i va reflechir dead = %i\n", philo->indice, *philo->dead);
		philo_think(philo);
	}
	return (NULL);
}
