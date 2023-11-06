/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:28:16 by besalort          #+#    #+#             */
/*   Updated: 2023/11/06 17:45:03 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	print_action(char *action, t_philo *philo)
{
	printf("%06ld %i %s\n", get_time(philo), philo->indice, action);
}

void	philo_sleep(t_philo *philo)
{
	if (philo->alive == 0)
		return ;
	print_action("is sleeping", philo);
	usleep(philo->time.time_sleep.tv_usec);
}

void	philo_eat(t_philo *philo)
{
	if (philo->alive == 0)
		return ;
	pthread_mutex_lock(philo->l_fork);
	print_action("has taken a fork", philo);
	pthread_mutex_lock(philo->r_fork);
	print_action("has taken a fork", philo);
	pthread_mutex_lock(&philo->eating);
	gettimeofday(&philo->time.last_meal, NULL);
	print_action("is eating", philo);
	pthread_mutex_unlock(&philo->eating);
	usleep(philo->time.time_eat.tv_usec);
	philo->meal += 1;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	philo_think(t_philo *philo)
{
	if (philo->alive == 0)
		return ;
	print_action("is thinking", philo);
}