/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:34:40 by besalort          #+#    #+#             */
/*   Updated: 2023/11/16 14:33:19 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	exit_philo(t_data *data)
{
	t_philo	*tmp;

	while (data->philo)
	{
		tmp = data->philo;
		pthread_mutex_destroy(&tmp->eating);
		data->philo = data->philo->next;
		free(tmp);
	}
	return (0);
}

int	init_data(t_data *data, int ac, char **av)
{
	data->dead = 0;
	if (pthread_mutex_init(&data->print, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&data->is_dead, NULL) != 0)
	{
		pthread_mutex_destroy(&data->print);
		return (-1);
	}
	convert_all(data, av);
	max_meal(data, ac, av);
	return (0);
}

int	philo(int ac, char **av)
{
	t_data	data;
	int		indice;

	data = (t_data){};
	indice = 0;
	if (is_only_number(av) != 1 || check_values(&data, av) != 0)
		return (ft_msg("Error: Wrong arguments"), -1);
	if (init_data(&data, ac, av) != 0)
		return (ft_msg("Error: Mutex"), exit_philo(&data), -1);
	setup_time(&data);
	data.philosophers = ft_atoi(av[1]);
	if (init_fork(&data) == -1)
		return (ft_msg("Error: Mutex"), exit_philo(&data), -1);
	data.philo = create_philo(&data, data.philosophers, indice);
	if (!data.philo)
		return (ft_msg("Error: Thread"), exit_philo(&data), -1);
	check_end(&data);
	return (exit_philo(&data));
}

int	main(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		printf("Error: wrong number of args, please use philo as: ");
		printf("./philo number_of_philosophers time_to_die ");
		printf("time_to_eat time_to_sleep ");
		printf("[number_of_time_a_philosopher_should_eat]\n");
		return (1);
	}
	else
		return (philo(ac, av));
}
