/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:03:27 by besalort          #+#    #+#             */
/*   Updated: 2023/10/23 17:30:19 by besalort         ###   ########.fr       */
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
		if (pthread_create(&philo->tid, NULL, thread_routine,
				(void *)data) != 0)
			exit(0);
		philo->indice = indice;
		philo->alive = 1;
		philo->next = create_philo(data, size - 1, indice + 1);
		if (philo->next == NULL && (size -1) > 0)
			return (free(philo), NULL);
	}
	return (philo);
}

	//Il faut : -gerer les fourchettes
	// -Faire un checker qui verifie si il faut les tuer
	// -Faire en sorte que les actions se refassent tant qu'ils ne sont pas morts
	// -Ajouter la possibilite de manger un certain nombre de fois max avant de quitter
	// On check a la fin et si il meurt on le tue et on dit qu'il est mort,
	// On modifie la valeur data->philo->alive a 0
void	*thread_routine(void *my_data)
{
	t_data			*data;
	struct timeval	actualtime;

	data = (t_data *)my_data;
	philo_sleep(data);
	printf("Je fonctionne\n");
	gettimeofday(&actualtime, NULL);
	if (data->time_die.tv_usec
		<= (actualtime.tv_usec - data->start_time.tv_usec))
		return (NULL);
	return (NULL);
}

int	thread_end(t_data *data)
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
