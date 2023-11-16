/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_thread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:52:34 by besalort          #+#    #+#             */
/*   Updated: 2023/11/16 16:34:15 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	end_thread(t_data *data, int indice)
{
	t_philo		*tmp;
	int			i;

	tmp = data->philo;
	i = 0;
	while (tmp && indice != -1)
	{
		if (tmp && tmp->indice == indice)
			printf("%ld %i died\n", get_time(tmp), tmp->indice + 1);
		tmp = tmp->next;
	}
	tmp = data->philo;
	while (tmp)
	{
		pthread_join(tmp->tid, NULL);
		tmp = tmp->next;
	}
	pthread_mutex_destroy(&data->is_dead);
	pthread_mutex_destroy(&data->print);
	while (i < data->philosophers - 1)
	{
		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
	free(data->fork);
}

int	check_out_time(t_philo *philo)
{
	if (philo->time.time_die / 1000 <= get_meal_time(philo))
	{
		pthread_mutex_lock(philo->is_dead);
		*philo->dead = 1;
		philo->alive = 0;
		pthread_mutex_unlock(philo->is_dead);
		return (1);
	}
	return (0);
}

void	make_dead(t_data *data)
{
	pthread_mutex_lock(&data->is_dead);
	data->dead = 1;
	pthread_mutex_unlock(&data->is_dead);
}

int	check_end(t_data *data)
{
	t_philo		*tmp;
	int			count;

	count = 0;
	while (count != data->philosophers)
	{
		count = 0;
		tmp = data->philo;
		while (tmp)
		{
			pthread_mutex_lock(&tmp->eating);
			if (check_out_time(tmp) == 1)
			{
				pthread_mutex_unlock(&tmp->eating);
				return (end_thread(data, tmp->indice), 1);
			}
			else if (data->meal_max != -1 && tmp->meal >= tmp->meal_max)
				count++;
			pthread_mutex_unlock(&tmp->eating);
			tmp = tmp->next;
		}
	}
	make_dead(data);
	return (end_thread(data, -1), 1);
}
