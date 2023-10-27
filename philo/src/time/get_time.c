/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:43:30 by besalort          #+#    #+#             */
/*   Updated: 2023/10/27 15:22:04 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

unsigned long	get_time(t_philo *philo)
{
	unsigned long time;

	gettimeofday(&philo->time.cmp, NULL);
	time = (philo->time.cmp.tv_sec - philo->time.start.tv_sec) * 1000
		+ (philo->time.cmp.tv_usec - philo->time.start.tv_usec) / 1000;
	return (time);
}