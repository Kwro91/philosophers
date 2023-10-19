/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:34:40 by besalort          #+#    #+#             */
/*   Updated: 2023/10/19 13:49:24 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	*create_philo(int size, int indice)
{
	t_philo	*philo;

	philo = NULL;
	if (size > 0)
	{
		philo = malloc(sizeof(t_philo));
		if (!philo)
			return (NULL);
		philo->indice = indice;
		philo->left = 0;
		philo->right = 0;
		philo->next = create_philo(size - 1, indice + 1);
		if (philo->next == NULL && (size -1) > 0)
			return (free(philo), NULL);
	}
	return (philo);
}

void	philo()
{
	
}

int main (int ac, char **av)
{
	(void)av;
	if (ac < 5)
	{
		printf("Wrong number of args, please use philo as: ");
		printf("./philo number_philosophers time_to_die time_to_eat time_to_sleep\n");
		return (0);
	}
}