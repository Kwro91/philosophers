/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:34:40 by besalort          #+#    #+#             */
/*   Updated: 2023/11/10 14:38:26 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	exit_philo(t_data *data)
{
	t_philo *tmp;
	
	while (data->philo)
	{
		tmp = data->philo;
		pthread_mutex_destroy(&tmp->eating);
		data->philo = data->philo->next;
		free(tmp);
	}
}

void	init_data(t_data *data)
{
	data->dead = 0;
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->is_dead, NULL);
}

void	philo(int ac, char **av)
{
	t_data	data;
	int		indice;

	data = (t_data){};
	indice = 0;
	if (is_only_number(av) != 1)
		return ;
	init_data(&data);
	convert_all(&data, av);
	max_meal(&data, ac, av);
	setup_time(&data);
	data.philosophers = ft_atoi(av[1]);
	if (init_fork(&data) == -1)
		return ;
	data.philo = create_philo(&data, data.philosophers, indice);
	check_end(&data);
	exit_philo(&data);
}

int	main(int ac, char **av)
{
	if (ac < 5)
	{
		printf("Wrong number of args, please use philo as: ");
		printf("./philo number_of_philosophers time_to_die ");
		printf("time_to_eat time_to_sleep ");
		printf("[number_of_time_a_philosopher_should_eat]\n");
		return (0);
	}
	else
		philo(ac, av);
}
