/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:34:40 by besalort          #+#    #+#             */
/*   Updated: 2023/10/31 18:20:36 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	exit_philo(t_data *data)
{
	t_philo *tmp;
	
	tmp = data->philo;
	while (tmp)
	{
		pthread_join(tmp->tid, NULL);
		tmp = tmp->next;
	}
}

void	philo(int ac, char **av)
{
	t_data	data;
	int		indice;

	data = (t_data){};
	indice = 0;
	if (is_only_number(av) != 1)
		exit(0);
	convert_all(&data, av);
	max_meal(&data, ac, av);
	setup_time(&data);
	data.philosophers = ft_atoi(av[1]);
	init_all(&data);
	data.philo = create_philo(&data, data.philosophers, indice);
	check_end(&data);
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
