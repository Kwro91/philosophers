/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:43:30 by besalort          #+#    #+#             */
/*   Updated: 2023/10/25 17:04:33 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

unsigned long	get_time(t_data *data)
{
	unsigned long time;


	gettimeofday(&data->stop_time, NULL);
	time = (data->stop_time.tv_sec - data->start_time.tv_sec) * 1000
		+ (data->stop_time.tv_usec - data->start_time.tv_usec) / 1000;
	return (time);
}