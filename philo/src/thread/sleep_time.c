/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:30:11 by besalort          #+#    #+#             */
/*   Updated: 2023/11/16 13:30:36 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

unsigned long	get_now_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	sleep_time(t_philo *philo, unsigned long sleep)
{
	unsigned long	time;

	time = get_now_time();
	pthread_mutex_lock(philo->is_dead);
	while (*philo->dead != 1)
	{
		pthread_mutex_unlock(philo->is_dead);
		if ((get_now_time() - time) >= sleep / 1000)
		{
			return ;
		}
		usleep(50);
		pthread_mutex_lock(philo->is_dead);
	}
	pthread_mutex_unlock(philo->is_dead);
}
