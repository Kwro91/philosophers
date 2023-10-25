/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:28:16 by besalort          #+#    #+#             */
/*   Updated: 2023/10/25 17:43:26 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	philo_sleep(t_data *data)
{
	pthread_t	self;
	t_philo		*philo;

	philo = data->philo;
	self = pthread_self();
	while (philo->next && self != philo->tid)
	{
		philo = philo->next;
	}
	gettimeofday(&data->stop_time, NULL);
	printf("%06ld %i is sleeping\n", get_time(data), philo->indice);
	usleep(data->time_sleep.tv_usec);
}
