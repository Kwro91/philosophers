/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:03:27 by besalort          #+#    #+#             */
/*   Updated: 2023/10/27 18:11:43 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	fill_times(t_data *data, t_philo *philo)
{
	gettimeofday(&philo->time.start, NULL);
	philo->time.time_die = data->time_die;
	philo->time.time_eat = data->time_eat;
	philo->time.time_sleep = data->time_sleep;
}

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
				(void *)philo) != 0)
			exit(0);
		philo->indice = indice;
		fill_times(data, philo);
		get_fork(data, philo, indice);
		philo->alive = 1;
		philo->meal = 0;
		philo->next = create_philo(data, size - 1, indice + 1);
		if (philo->next == NULL && (size -1) > 0)
			return (free(philo), NULL);
	}
	return (philo);
}

	//Il faut :
	// -CHECKER AVANT CHAQUE ACTION QUE LE PHILO EST EN VIE POUR FAIRE L'ACTION
	// -Faire en sorte que les actions se refassent tant qu'ils ne sont pas morts
	// -Ajouter la possibilite de manger un certain nombre de fois max avant de quitter
void	*thread_routine(void *my_philo)
{
	t_philo	*philo;
	philo = (t_philo *)my_philo;
	if (!philo)
		return (NULL);
	while (philo->alive == 1 && philo->meal < 3)
	{
		philo_sleep(philo);
		if ((unsigned long)(philo->time.time_die.tv_usec)/1000 <= (get_time(philo)))
		{
			philo->alive = 0;
			printf("%06ld %i died\n", get_time(philo), philo->indice);
			return (NULL);
		}
		philo->meal += 1;
	}
	pthread_join(philo->tid, NULL);
	return (NULL);
}

void	end_thread(t_data *data)
{
	t_philo		*tmp;

	tmp = data->philo;
	while (tmp->next)
	{
		if (tmp->alive == 1)
		{
			tmp->alive = 0;
			pthread_join(tmp->tid, NULL);
		}
	}
}

int	check_end(t_data *data)
{
	t_philo		*tmp;
	
	tmp = data->philo;
	while (tmp->next)
	{
		if (tmp->alive == 0)
		{
			end_thread(data);
			// printf("%06ld %i died\n", get_time(data), data->philo->indice);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
