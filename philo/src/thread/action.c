/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:28:16 by besalort          #+#    #+#             */
/*   Updated: 2023/11/09 18:06:56 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	print_action(char *action, t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	if (*philo->dead != 1)
		printf("%06ld %i %s\n", get_time(philo), philo->indice + 1, action);
	pthread_mutex_unlock(philo->print);
}

void	philo_sleep(t_philo *philo)
{
	pthread_mutex_lock(philo->is_dead);
	if (*philo->dead == 0)
	{
		print_action("is sleeping", philo);
		pthread_mutex_unlock(philo->is_dead);
		usleep(philo->time.time_sleep.tv_usec);
	}
	else
		pthread_mutex_unlock(philo->is_dead);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->is_dead);
	if (*philo->dead == 0)
	{
		pthread_mutex_unlock(philo->is_dead);
		pthread_mutex_lock(philo->l_fork);
		print_action("has taken a fork", philo);
		pthread_mutex_lock(philo->r_fork);
		print_action("has taken a fork", philo);
		pthread_mutex_lock(&philo->eating);
		gettimeofday(&philo->time.last_meal, NULL);
		print_action("is eating", philo);
		usleep(philo->time.time_eat.tv_usec);
		philo->meal += 1;
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(&philo->eating);
	}
	else
		pthread_mutex_unlock(philo->is_dead);
}

void	philo_think(t_philo *philo)
{
	pthread_mutex_lock(philo->is_dead);
	if (philo->dead == 0)
	{
		pthread_mutex_unlock(philo->is_dead);
		print_action("is thinking", philo);
	}
	else
		pthread_mutex_unlock(philo->is_dead);
}