/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:18:19 by besalort          #+#    #+#             */
/*   Updated: 2023/11/10 14:54:59 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	init_fork(t_data *data)
{
	int	i;

	i = 0;
	data->fork = malloc(sizeof(pthread_mutex_t) * data->philosophers);
	if (!data->fork)
		return (-1);
	while (i < data->philosophers)
	{
		pthread_mutex_init(&data->fork[i], NULL);
		i++;
	}
	return (0);
}

void	get_fork(t_data *data, t_philo *philo, int indice)
{
	if (philo->indice + 1 == (data->philosophers))
	{
		philo->l_fork = &data->fork[indice];
		philo->r_fork = &data->fork[0];
	}
	else
	{
		philo->l_fork = &data->fork[indice];
		philo->r_fork = &data->fork[indice + 1];
	}
}
