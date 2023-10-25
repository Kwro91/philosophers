/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:18:19 by besalort          #+#    #+#             */
/*   Updated: 2023/10/25 17:25:57 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

t_fork	*create_fork(int size, int indice)
{
	t_fork			*fork;
	pthread_mutex_t	mutex;

	fork = NULL;
	if (size > 0)
	{
		fork = malloc(sizeof(t_fork));
		if (!fork)
			return (NULL);
		pthread_mutex_init(&mutex, NULL);
		fork->fork = mutex;
		fork->indice = indice;
		fork->next = create_fork(size - 1, indice - 1);
		if (fork->next == NULL && (size -1) > 0)
			return (free(fork), NULL);
	}
	return (fork);
}
