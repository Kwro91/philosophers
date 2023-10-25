/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:34:40 by besalort          #+#    #+#             */
/*   Updated: 2023/10/25 17:48:28 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo(char **av)
{
	t_data	data;
	int		indice;

	data = (t_data){};
	indice = 1;
	if (is_only_number(av) != 1)
		exit(0);
	convert_all(&data, av);
	data.fork = create_fork(atoi(av[1]), indice);
	setup_time(&data);
	data.philo = create_philo(&data, atoi(av[1]), indice);
	thread_end(&data);
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
		philo(av);
}
