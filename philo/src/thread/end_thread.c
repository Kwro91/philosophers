/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_thread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:52:34 by besalort          #+#    #+#             */
/*   Updated: 2023/11/06 17:57:57 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	end_thread(t_data *data)
{
	t_philo		*tmp;
	int			i;

	tmp = data->philo;
	i = 0;
	while (i < 200)
	{
		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
	while (tmp)
	{
		printf("On fais mourir %i, alive = %i\n", tmp->indice, tmp->alive);
		pthread_join(tmp->tid, NULL);
		if (tmp->alive == 0)
			print_action("died", tmp);
		tmp = tmp->next;
	}
}

int	check_all_ate(t_data *data)
{
	t_philo	*tmp;
	int		philo_max;

	tmp = data->philo;
	philo_max = 0;
	if (data->meal_max == -1)
		return (0);
	while (tmp)
	{
		if (tmp->meal < tmp->meal_max)
		{
			philo_max++;
			if (philo_max == data->philosophers)
				return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

int	check_out_time(t_philo *philo)
{
	if ((unsigned long)philo->time.time_die.tv_usec / 1000 <= get_meal_time(philo))
	{
		philo->alive = 0;
		return (1);
	}
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
			{
				printf("%i run out of time\n", tmp->indice);
				return (end_thread(data), 1);
			}
			// printf("%06ld / 1000 <= %06ld\n", (unsigned long)data->time_die.tv_usec, get_meal_time(tmp));
			if (tmp->alive == 0 || check_all_ate(data) == 1)
			{
				printf("%i est mort (alive = %i) ou trop mange (%i / %i )\n", tmp->indice, tmp->alive, tmp->meal, tmp->meal_max);
				return (end_thread(data), 1);
			}
			pthread_mutex_unlock(&tmp->eating);
			tmp = tmp->next;
		}
	}
	return (0);
}
