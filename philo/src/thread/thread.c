/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:03:27 by besalort          #+#    #+#             */
/*   Updated: 2023/10/19 18:35:46 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

t_philo	*create_philo(t_data *data, int size, int indice)
{
	t_philo	*philo;

	philo = NULL;
	if (size > 0)
	{
		philo = malloc(sizeof(t_philo));
		if (!philo)
			return (NULL);
		if (pthread_create(&philo->tid, NULL, thread_routine, &data) != 0)
			exit(0);
		philo->indice = indice;
		philo->alive = 1;
		philo->next = create_philo(data, size - 1, indice + 1);
		if (philo->next == NULL && (size -1) > 0)
			return (free(philo), NULL);
	}
	return (philo);
}

void	*thread_routine(void *data)
{
	struct timeval start_time;
	
	gettimeofday(&start_time, NULL);
	//start_time.tv_sec // start_time.tv_usec pour avoir le temps actuel, faut le refaire et le soustraire pour avor la bonne value
	data = (t_data *)data;
	printf("Je fonctionne\n");
	//On check a la fin et si il meurt on le tue et on dit qu'il est mort, on modifie la valeur data->philo->alive a 0
	//Comme ca on saura lequel est mort en premier et on evitera de le pthread_join apres
	return (NULL);
}

int		thread_end(t_data *data)
{
	while (data->philo)
	{
		if (data->philo->alive == 1)
		{
			pthread_join(data->philo->tid, NULL);
			printf("Le philosophe %i meurt\n", data->philo->indice);
			data->philo->alive = 0;
		}
		data->philo = data->philo->next;
	}
	return (0);
}