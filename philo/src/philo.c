/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:34:40 by besalort          #+#    #+#             */
/*   Updated: 2023/10/19 18:09:33 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo(char **av)
{
	t_data	data;
	int	indice;

	data = (t_data){};
	indice = 1;
	data.fork = create_fork(atoi(av[1]), indice);
	data.philo = create_philo(&data, atoi(av[1]), indice);
	thread_end(&data);
}

int main (int ac, char **av)
{
	if (ac < 5)
	{
		printf("Wrong number of args, please use philo as: ");
		printf("./philo number_of_philosophers time_to_die ");
		printf("time_to_eat time_to_sleep\n");
		return (0);
	}
	else
		philo(av);
}