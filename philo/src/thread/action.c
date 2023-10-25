/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:28:16 by besalort          #+#    #+#             */
/*   Updated: 2023/10/25 15:48:33 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	philo_sleep(t_data *data)
{
	pthread_t self;

	gettimeofday(&data->stop_time, NULL);
	self = pthread_self();
	printf("%06ld %ld is sleeping\n", get_time(data), self);
	usleep(data->time_sleep.tv_usec);
}
