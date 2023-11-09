/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_thread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:52:34 by besalort          #+#    #+#             */
/*   Updated: 2023/11/09 19:49:25 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	end_thread(t_data *data, int indice)
{
	t_philo		*tmp;
	int			i;

	tmp = data->philo;
	i = 0;
	while (i < data->philosophers - 1)
	{
		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
	while (tmp)
	{
		tmp->alive = 0;
		if (tmp->indice == indice)
			printf("%06ld %i died\n", get_time(tmp), tmp->indice + 1);
		tmp = tmp->next;
	}
	tmp = data->philo;
	while (tmp)
	{
		pthread_join(tmp->tid, NULL);
		tmp = tmp->next;
	}
}

int	check_all_ate(t_data *data)
{
	t_philo	*tmp;
	int		count;

	tmp = data->philo;
	count = 0;
	if (data->meal_max == -1)
		return (0);
	while (tmp)
	{
		if (tmp->meal >= tmp->meal_max)
		{
			count++;
			if (count == data->philosophers)
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	check_out_time(t_philo *philo)
{
	pthread_mutex_lock(philo->is_dead);
	if ((unsigned long)philo->time.time_die.tv_usec / 1000 <= get_meal_time(philo))
	{
		*philo->dead = 1;
		pthread_mutex_unlock(philo->is_dead);
		philo->alive = 0;
		return (1);
	}
	else
		pthread_mutex_unlock(philo->is_dead);
	return (0);
}

int	check_end(t_data *data)
{
	t_philo		*tmp;

	while (1)
	{
		tmp = data->philo;
		while (tmp)
		{
			pthread_mutex_lock(&tmp->eating);
			if (check_out_time(tmp) == 1)
				return (end_thread(data, tmp->indice), 1);
			if (tmp->alive == 0 || check_all_ate(data) == 1)
				return (end_thread(data, -1), 1);
			pthread_mutex_unlock(&tmp->eating);
			tmp = tmp->next;
		}
	}
	return (0);
}
