/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:18:19 by besalort          #+#    #+#             */
/*   Updated: 2023/10/31 17:31:25 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	init_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < 200)
	{
		pthread_mutex_init(&data->fork[i], NULL);
		i++;
	}
}

void	get_fork(t_data *data, t_philo *philo, int indice)
{
	if (philo->next == NULL)
	{
		philo->l_fork = data->fork[indice];
		philo->r_fork = data->fork[0];
	}
	else
	{
		philo->l_fork = data->fork[indice];
		philo->r_fork = data->fork[indice + 1];
	}
}
