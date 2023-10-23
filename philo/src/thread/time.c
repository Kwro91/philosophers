/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:28:23 by besalort          #+#    #+#             */
/*   Updated: 2023/10/23 14:55:42 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	setup_time(t_data *data)
{
	struct timeval	start_time;

	gettimeofday(&start_time, NULL);
	data->start_time = start_time;
	return (1);
}